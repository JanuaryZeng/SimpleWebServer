//
// Created by zxj on 2022/3/21.
//

#include "../../include/server/webServer.h"

webServer::webServer() {
    users = std::vector<std::shared_ptr<http_conn>>(MAX_FD);

    for(int i = 0; i < MAX_FD; ++i){
        users[i] = std::make_shared<http_conn>();
    }

    //root文件夹路径
    char server_path[200];
    char *root_path = getcwd(server_path, 200);
    //TODO:打印
    char root[6] = "/root";
    root_dir.append(server_path);
    root_dir.append(root);
}

webServer::~webServer() {
    close(epollfd);
    close(listenfd);
}

void webServer::init() {
    port = 10001;
    thread_num = 4;
    max_requests = 10000;
    timeout = false;
    stop_server = false;
    //线程池初始化
    thread_pool = std::make_shared<threadpool<http_conn>>(thread_num, max_requests);
    initIO();
}

void webServer::initIO() {
    listenfd = open_listenfd(port);
    if(setnonblocking(listenfd) == -1){
        abort();
    }
    epollfd = epoll_create(5);
    if(-1 == epollfd){
        abort();
    }
    http_conn::m_epollfd = epollfd;

    epoll_event event;
    event.data.fd = listenfd;
    event.events = EPOLLIN | EPOLLRDHUP;

    epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &event);
    setnonblocking(epollfd);

}