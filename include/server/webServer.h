//
// Created by zxj on 2022/3/21.
//

#ifndef SIMPLESERVER_WEBSERVER_H
#define SIMPLESERVER_WEBSERVER_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdio>
#include <unistd.h>
#include <cerrno>
#include <fcntl.h>
#include <cstdlib>
#include <cassert>
#include <sys/epoll.h>

#include <memory>
#include <vector>

#include "../thread_pool/thread_pool.h"
#include "../http_conn/http_conn.h"
#include "../util/config.h"
#include "../util/util.h"


const int MAX_FD = 65536;           //最大文件描述符
const int MAX_EVENT_NUMBER = 10000; //最大事件数
const int TIMESLOT = 5;             //最小超时单位

class webServer {
public:
    webServer();
    ~webServer();
    //void init(Config config);
    void init();
    void loop();

private:

    void adjustTimer(std::shared_ptr<heap_timer> timer);
    void initHttpConn(int connfd, struct sockaddr_in client_address);
    bool acceptClient();
    bool dealTimer();
    bool dealSignal();
    void dealRead(int sockfd);
    void dealWrite(int sockfd);

    void initIO();

    //基础
    int port;
    std::string root_dir;
    int close_log;

    std::vector<std::shared_ptr<http_conn>> users;

    //线程池相关
    std::shared_ptr<threadpool<http_conn>> thread_pool;
    int thread_num;
    int max_requests;

    //epoll相关
    int epollfd;
    epoll_event events[MAX_EVENT_NUMBER];

    int listenfd;
    int ope_linger;

    //定时器

    //信号处理相关
    bool timeout = false;
    bool stop_server = false;
};

#endif //SIMPLESERVER_WEBSERVER_H
