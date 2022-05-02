#include <iostream>
#include <sys/socket.h>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <signal.h>
#include <cstring>
#include <vector>
#include "../include/thread_pool/thread_pool.h"
#include "../include/lock/lock.h"
#include "../include/http_conn/http_conn.h"

#define MAX_DF 65535//最大文件描述符个数
#define MAX_EVENT_NUMBER 10000 //最大事件数

//添加信号捕捉
void addsig(int sig, void(handler)(int)){
    struct sigaction sa;
    memset(&sa,'\0',sizeof(sa));
    sa.sa_handler = handler;
    sigfillset(&sa.sa_mask);
    sigaction(sig, &sa, NULL);
}

//添加文件描述符到epoll中
extern void addfd(int epolldf, int fd, bool one_shot);
//从epoll中删除文件描述符
extern void removefd(int epollfd, int fd);
//修改文件描述符
extern void modfd(int epollfd, int fd, int ev);

int main(int argc, char* argv[]) {
    if(argc <= 1){
        printf("按照如下方式运行：%s port_number\n", basename(argv[0]));
        exit(-1);
    }

    int port = atoi(argv[1]);

    //对SIGPIE信号进行处理
    addsig(SIGPIPE, SIG_IGN);

    //创建线程池，初始化线程池
    std::shared_ptr<threadpool<http_conn>> pool;
    try{
        pool = std::make_shared<threadpool<http_conn>>();
    }catch(...){
        exit(1);
    }

    //创建一个数组用于保存所有客户端的信息
    std::vector<http_conn> users(MAX_DF);

    int listenfd = socket(PF_INET, SOCK_STREAM, 0);

    //端口复用
    int reuse = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    //绑定
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    bind(listenfd, (struct sockaddr*) &address, sizeof(address));

    //监听
    listen(listenfd, 5);

    //创建epoll对象，事件数组，添加
    epoll_event events[MAX_EVENT_NUMBER];
    int epollfd = epoll_create(5);

    //将监听的文件描述符
    addfd(epollfd, listenfd, false);
    http_conn::m_epollfd = epollfd;

    while(true){
        int num = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
        if(num < 0 && errno != EINTR){
            printf("epoll failure\n");
            break;
        }
        //循环遍历
        for(int i = 0; i < num; ++i){
            int sockfd = events[i].data.fd;
            if(sockfd == listenfd){
                //有客服端连接服务器
                struct sockaddr_in client_address;
                socklen_t client_address_len = sizeof (client_address);
                int connfd = accept(listenfd, (struct sockaddr*)&client_address, & client_address_len);
                if(http_conn::m_user_count >= MAX_DF){
                    //目前连接数满了
                    //给客户端写一个信息：服务器正忙
                    close(connfd);
                    continue;
                }
                //将新的客户的数据初始化，放到数组中
                users[connfd].init(connfd, client_address);
            }else if(events[i].events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR)){
                //对方异常断开
                users[sockfd].close_conn();
            }else if(events[i].events & EPOLLIN){
                if(users[sockfd].read()){
                    //一次性把所有数据都读完
                    pool->append(std::shared_ptr<http_conn>(&users[sockfd]));
                }else{
                    users[sockfd].close_conn();
                }
            }else if(events[i].events & EPOLLOUT){
                if(!users[sockfd].write()){

                }else{

                }
            }
        }
    }

    close(epollfd);
    close(listenfd);

    return 0;
}
