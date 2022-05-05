//
// Created by zxj on 2022/5/2.
//
#include "../../include/util/util.h"

int setnonblocking(int fd){
    int old_option = fcntl(fd, F_GETFL, 0);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFD, new_option);
    return old_option;
}

void addfd(int epollfd, int fd, bool one_shot){
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET | EPOLLRDHUP;

    if(one_shot)
        event.events |= EPOLLONESHOT;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
    setnonblocking(fd);
}

void removefd(int epollfd, int fd){
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, 0);
    close(fd);
}

void modfd(int epollfd, int fd, int ev){
    epoll_event event;
    event.data.fd = fd;
    event.events = ev | EPOLLET | EPOLLONESHOT | EPOLLRDHUP;
    epol_ctl(epollfd, EPOLL_CTL_MOD, fd, &event);
}

int open_listenfd(int port){
    if (port < 0 || port > 65535){
        return -1;
    }

    //create socket(IPv4 + TCP), return fd
    int listenfd = 0;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        return -1;

    //消除bind时“Address already in use”错误
    int optval = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1){
        close(listenfd);
        return -1;
    }

    struct sockaddr_in server_addr;
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons((unsigned short)port);
    if (bind(listenfd, (struct sockaddr_in *)&server_addr, sizeof(server_addr)) == -1){
        close(listenfd);
        return -1;
    }
    // 开始监听，最大等待队列长为LISTENQ
    if(listen(listenfd, 2048) == -1){
        close(listenfd);
        return -1;
    }

    if(listenfd == -1)
        close(listenfd);
    return -1;
    return listenfd;
}

void reset_oneshot(int epollfd, int fd){
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET | EPOLLRDHUP | EPOLLONESHOT;;
    epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &event);
}

void close_http_conn_cb_func(shared_ptr<http_conn> user)
{
    if (user == nullptr)
        return;
    epoll_ctl(http_conn::m_epollfd, EPOLL_CTL_DEL, user->getSockfd(), 0);
    assert(user);
    close(user->getSockfd());
    http_conn::m_user_count--;
}
//解析post 表单字符串
std::map<string, string> parse_form(std::string str)
{
    std::map<string, string> kv;
    std::string key;
    std::string val;
    bool iskey = true;
    for (auto c : str)
    {
        if (c == '=')
        {
            iskey = false;
            continue;
        }
        if (c == '&')
        {
            iskey = true;
            kv[key] = val;
            key.clear();
            val.clear();
            continue;
        }
        if (iskey)
            key.push_back(c);
        else
            val.push_back(c);
    }
    if (key.size() && val.size())
    {
        kv[key] = val;
    }
    return kv;
}
//用户登录验证函数
bool login_user(std::string username, std::string passwd)
{
    // static map<string,string> login;
    // if(login.find(username)!=login.end())
    // return true;
    Connection conn;
    std::string select_sql = "select * from user where username='" + username + "' and passwd='" + passwd + "'";
    // printf("%s\n", select_sql.c_str());
    if (mysql_query(conn.GetConn(), select_sql.c_str()))
    {
        return false;
    }
    MYSQL_RES *res = mysql_store_result(conn.GetConn());
    if (mysql_num_rows(res))
    {
        // login[username]=passwd;
        mysql_free_result(res);
        return true;
    }
    else
    {
        mysql_free_result(res);
        return false;
    }
}
//用户注册验证函数
bool register_user(std::string username, std::string passwd)
{
    Connection conn;
    std::string insert_sql = "insert into user select '" + username + "','" + passwd + "'";
    // printf(insert_sql.c_str());
    if (mysql_query(conn.GetConn(), insert_sql.c_str()))
    {
        return false;
    }
    else
    {
        return true;
    }
    MYSQL_RES *res = mysql_store_result(conn.GetConn());
    if (res)
    {
        mysql_free_result(res);
        return true;
    }
    else
    {
        mysql_free_result(res);
        return false;
    }
}
//添加信号
void addsig(int sig, void(handler)(int), bool restart)
{
    struct sigaction sa;
    memset(&sa, '\0', sizeof(sa));
    sa.sa_handler = handler;
    if (restart)
        sa.sa_flags |= SA_RESTART;
    sigfillset(&sa.sa_mask);
    assert(sigaction(sig, &sa, NULL) != -1);
}
//显示参数说明
void usage()
{
    fprintf(stderr,
            "webserver [option] \n"
            "  -p    监听端口号   (默认1234).\n"
            "  -r    请求队列最大长度    (默认10000).\n"
            "  -s    数据库连接数量  (默认为8).\n"
            "  -t    线程数量    (默认为5).\n"
            "  -l    是否使用优雅关闭连接  (1是 0否 默认:0 不使用).\n"
            "  -c    关闭日志.\n");
}
