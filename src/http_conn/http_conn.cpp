//
// Created by zxj on 2022/3/28.
//

#include "../../include/http_conn/http_conn.h"
int http_conn::m_epollfd = -1;
int http_conn::m_user_count = 0;

http_conn::http_conn() {

}

http_conn::~http_conn() {

}




void http_conn::init(int sockfd, const sockaddr_in &addr) {
    m_sockfd = sockfd;
    m_address = addr;

    //端口复用
    int reuse = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    //添加到对象中
    addfd(m_epollfd, sockfd, true);
    m_user_count++;
    init();
}

void http_conn::init() {
    m_check_state = CHECK_STATE_REQUESTLINE;//初始化状态是解析请求首行
    m_check_index = 0;
    m_start_line = 0;
    m_read_idx = 0;
    m_method = GET;
    m_url = 0;
    m_version = 0;
    m_linger = 0;
    bzero(m_read_buf, READ_BUFFER_SIZE);

}

void http_conn::close_conn() {
    if(m_sockfd != -1){
        removefd(m_epollfd, m_sockfd);
        m_sockfd = -1;
        m_user_count--;
    }
}

//解析HTTP请求 主状态机
http_conn::HTTP_CODE http_conn::process_read(){

    LINE_STATUS line_state = LINE_OK;
    HTTP_CODE ret = NO_REQUEST;

    char *text = 0;

    while(((m_check_state == CHECK_STATE_CONTENT) && (line_state == LINE_OK))
    ||(line_state = parse_line()) == LINE_OK){
        //解析到一行完整的数据，或者解析到了请求体，也是完成的数据
        //获取一行数据
        text = get_line();

        m_start_line = m_check_index;
        printf("got 1 http line : %s\n", text);
        switch(m_check_state){
            case CHECK_STATE_REQUESTLINE:
            {
                ret = parse_request_line(text);
                if(ret == BAD_REQUEST){
                    return BAD_REQUEST;
                }
                break;
            }
            case CHECK_STATE_HEADER:
            {
                ret = parse_headers(text);
                if(ret == BAD_REQUEST){
                    return BAD_REQUEST;
                }else if(ret == GET_REQUEST){
                    return do_request();
                }
            }
            case CHECK_STATE_CONTENT:
            {
                ret = parse_content(text);
                if(ret == GET_REQUEST){
                    return do_request();
                }
                line_state = LINE_OPEN;
                break;
            }
            default:
            {
                return INTERNAL_ERROR;
            }
        }
    }

    return NO_REQUEST;
}
//解析请求首行
http_conn::HTTP_CODE http_conn::parse_request_line(char *text){
    //GET /index.html HTTP/1.1
    m_url = strpbrk(text," \t");
    //GET\0/index.html HTTP/1.1
    *m_url++='\0';

    char* method = text;

    if(strcasecmp(method, "GET") == 0){
        m_method = GET;
    }else{
        return BAD_REQUEST;
    }
    // /index.html HTTP/1.1
    m_version = strpbrk(m_url, " \t");
    if(!m_version){
        return BAD_REQUEST;
    }
    // /index.html\0HTTP/1.1
    *m_version++ = '\0';
    if(strcasecmp(method, "HTTP/1.1") != 0){
        return BAD_REQUEST;
    }
    // http://192.168.1.1:10000/index.html
    if(strncasecmp(m_url, "http://", 7) == 0){
        m_url += 7;// 192.168.1.1:10000/index.html
        m_url = strchr(m_url, '/');// /index.html
    }

    if(!m_url || m_url[0] != '/')
        return BAD_REQUEST;

    m_check_state = CHECK_STATE_HEADER;//主状态机检查请求头

    return NO_REQUEST;
}
//解析HTTP请求头
http_conn::HTTP_CODE http_conn::parse_headers(char *text){
    return NO_REQUEST;
}
//解析HTTP请求体
http_conn::HTTP_CODE http_conn::parse_content(char *text){
    return NO_REQUEST;
}
//解析一行
http_conn::LINE_STATUS http_conn::parse_line(){
    char temp;
    for(;m_check_index < m_read_idx; ++m_check_index){
        temp = m_read_buf[m_check_index];
        if(temp == '\r'){
            if(m_check_index + 1 == m_read_idx){
                return LINE_OPEN;
            }else if(m_read_buf[m_check_index+1]=='\n'){
                m_read_buf[m_check_index++] = '\0';
                m_read_buf[m_check_index]='\0';
                return LINE_OK;
            }
            return LINE_BAD;
        }else if(temp == '\n'){
            if(m_check_index>1 && m_read_buf[m_check_index-1] == '\r'){
                m_read_buf[m_check_index-1]='\0';
                m_read_buf[m_check_index++]='\0';
                return LINE_OK;
            }
        }
        return LINE_OPEN;
    }
    return LINE_OK;
}

http_conn::HTTP_CODE http_conn::do_request(){
    return GET_REQUEST;
}

//循环读取客户数据
bool http_conn::read() {
    if(m_read_idx >= READ_BUFFER_SIZE){
        return false;
    }
    int bytes_read = 0;

    while(true){
        bytes_read = recv(m_sockfd, m_read_buf + m_read_idx, READ_BUFFER_SIZE-m_read_idx,0);
        if(bytes_read == -1){
            if(errno == EAGAIN || errno == EWOULDBLOCK){
                break;
            }
            return false;
        }else if(bytes_read == 0){
            //对方关闭连接
            return false;
        }
        m_read_idx += bytes_read;
    }

    printf("读取到的数据\n%s\n",m_read_buf);
    return true;
}

bool http_conn::write() {
    printf("一次性写完\n");
    return true;
}

void http_conn::process() {
    //解析HTTP请求
    //process_read();

    HTTP_CODE read_ret =  process_read();
    if(read_ret == NO_REQUEST){
        modfd(m_epollfd, m_sockfd, EPOLLIN);
        return;
    }

    printf("解析HTTP，生成响应\n");
    //生成响应
}

void http_conn::run()
{
//    if (0 == m_state)
//    {
//        if (read())
//        {
            process();
//        }
//        else
//        {
//            close_conn();
//        }
//    }
//    else
//    {
//        if (!write())
//        {
//            close_conn();
//        }
//    }
}