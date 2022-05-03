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
