#ifndef WEBSERVER_HTTP_CONN_H_
#define WEBSERVER_HTTP_CONN_H_

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cassert>
#include <sys/stat.h>
#include <cstring>
#include <string>
#include <pthread.h>
#include <cstdio>
#include <cstdlib>
#include <sys/mman.h>
#include <cstdarg>
#include <cerrno>
#include <sys/wait.h>
#include <sys/uio.h>
#include <unordered_map>
#include <iostream>

#include "../lock/locker.h"
#include "../connection_pool/connection_pool.h"
#include "../log/logger.h"
#include "../timer/timer.h"
#include "../util/util.h"
#include "../http/session.h"
struct FileStat{
    FileStat(struct stat _status,char *_addrass):status(_status),address(_addrass),usage_times(1){}
    ~FileStat(){
       munmap(address, status.st_size);
    }
    struct stat status;
    char * address;
    uint32_t usage_times;//使用次数
};

class http_conn
{
public:
    static const int FILENAME_LEN = 200;
    static const int READ_BUFFER_SIZE = 2048;
    static const int WRITE_BUFFER_SIZE = 2048;
    static const int CACHE_SIZE = 16;
    enum METHOD //http 头部方法
    {
        GET = 0,
        POST
    };
    enum CHECK_STATE //http请求解析状态
    {
        CHECK_STATE_REQUESTLINE = 0,
        CHECK_STATE_HEADER,
        CHECK_STATE_CONTENT
    };
    enum HTTP_CODE //响应码
    {
        NO_REQUEST,
        GET_REQUEST,
        POST_REQUEST,
        BAD_REQUEST,
        NO_RESOURCE,
        FORBIDDEN_REQUEST,
        FILE_REQUEST,
        INTERNAL_ERROR,
        CLOSED_CONNECTION,
        TEST_REQUEST
    };
    enum LINE_STATUS //行解析状态
    {
        LINE_OK = 0,//读取一行成功
        LINE_BAD,//读取失败
        LINE_OPEN//全部读完
    };

public:
    http_conn() {}
    ~http_conn() {}

public:
    void run();
    void init(int sockfd, const sockaddr_in &addr, string root);
    int getSockfd()
    {
        return m_sockfd;
    }
    void setWrite()
    {
        m_state = 1;
    }
    void setRead()
    {
        m_state = 0;
    }
    void close_conn();

private:
    void init(); //初始化
    //读系列函数
    HTTP_CODE process_read();
    bool process_write(HTTP_CODE ret);
    HTTP_CODE parse_request_line(char *text);
    HTTP_CODE parse_headers(char *text);
    HTTP_CODE parse_content(char *text);
    HTTP_CODE do_get_request();
    HTTP_CODE do_post_request();
    char *get_line() { return m_read_buf + m_start_line; };
    LINE_STATUS parse_line();
    void unmap();
    //写系列函数
    bool add_response(const char *format, ...);
    bool add_content(const char *content);
    bool add_status_line(int status, const char *title);
    bool add_headers(int content_length);
    bool add_content_type();
    bool add_content_length(int content_length);
    bool add_cookie();
    bool add_linger();
    bool add_blank_line();
    bool add_test_reponse();

    //总体流程
    void process();
    bool read();
    bool write();

public:
    static int m_epollfd;
    static int m_user_count;
    static shared_ptr<TimeHeap> time_heap;
    static Session session; //session保存登录状态
    weak_ptr<heap_timer> timer;
    LOGIN_STATUS login_stat;
    string sessionid;

private:
    int m_state; //读为0, 写为1

private:
    int m_sockfd;
    sockaddr_in m_address;
    char m_read_buf[READ_BUFFER_SIZE];   //读缓冲区
    int m_read_idx;                      //已读取数据的下一个字符位置
    int m_checked_idx;                   //当前解析字符位置
    int m_start_line;                    //当前解析行第一个字符
    char m_write_buf[WRITE_BUFFER_SIZE]; //写缓冲区
    int m_write_idx;                     //已写缓冲长度
    CHECK_STATE m_check_state;           //主状态机当前状态
    METHOD m_method;                     //请求方法
    char m_real_file[FILENAME_LEN];      //目标文件路径
    char *m_url;                         //文件名
    char *m_version;                     //HTTP版本
    char *m_host;                        //主机名
    int m_content_length;
    bool keep_alive;
    shared_ptr<FileStat> file_stat;
    // char *m_file_address;
    // struct stat m_file_stat;
    struct iovec m_iv[2];
    int m_iv_count;

    char *m_content; //存储请求头数据
    size_t bytes_to_send;
    size_t bytes_have_send;
    string doc_root;
    static unordered_map<string,shared_ptr<FileStat> > file_cache;
    static locker file_mutex;
};
#endif //WEBSERVER_HTTP_CONN_H_
/**

 * char *strpbrk(const char *str1, const char *str2) 检索字符串 str1 中第一个匹配字符串 str2 中字符的字符，不包含空结束字符'\0'。
 * 该函数返回 str1 中第一个匹配字符串 str2 中字符的字符数，如果未找到字符则返回 NULL。

 * int strcasecmp (const char *s1, const char *s2); strcasecmp()用来比较参数s1 和s2 字符串，比较时会自动忽略大小写的差异。
 * 返回值：若参数s1 和s2 字符串相同则返回0。s1 长度大于s2 长度则返回大于0 的值，s1 长度若小于s2 长度则返回小于0的值。

 * size_t strspn(const char *str1, const char *str2)
 * str1 -- 要被检索的 C 字符串。
 * str2 -- 该字符串包含了要在 str1 中进行匹配的字符列表。
 * 该函数返回 str1 中第一个不在字符串 str2 中出现的字符下标。

 * char *strchr(const char *str, int c)
 * str -- 要被检索的 C 字符串。
 * c -- 在 str 中要搜索的字符。
 * 该函数返回在字符串 str 中第一次出现字符 c 的位置，如果未找到该字符则返回 NULL。

 *
 */
