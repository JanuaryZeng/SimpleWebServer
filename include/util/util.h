//
// Created by zxj on 2022/5/2.
//

#ifndef SIMPLESERVER_UTIL_H
#define SIMPLESERVER_UTIL_H

#include <cstdlib>
#include <string>
#include <map>
#include <memory>
#include <cerrno>
#include <fcntl.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <cstring>
#include <unistd.h>
#include "../http_conn/http_conn.h"

class http_conn;

//设置文件描述符为非阻塞
int setnonblocking(int fd);
//添加文件描述符到epoll
void addfd(int epollfd, int fd, bool one_shot);
//从epoll中删除描述符
void removefd(int epollfd, int fd);
//修改描述符监听事件
void modfd(int epollfd, int fd, int ev);
//创建并监听特定端口的描述符
int open_listenfd(int port);
//重置描述法EPOLLONESHOT
void reset_oneshot(int epollfd, int fd);

void close_http_conn_cb_func(std::shared_ptr<http_conn> user);

std::map<std::string, std::string> parse_form(std::string str);

bool login_user(std::string username, std::string passwd);

bool register_user(std::string username, std::string passwd);

void addsig(int sig, void(handler)(int), bool restart = true);


#endif //SIMPLESERVER_UTIL_H
