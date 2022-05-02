//
// Created by zxj on 2022/3/21.
//

#ifndef SIMPLESERVER_WEBSERVER_H
#define SIMPLESERVER_WEBSERVER_H
const int MAX_FD = 65536;           //最大文件描述符
const int MAX_EVENT_NUMBER = 10000; //最大事件数
const int TIMESLOT = 5;             //最小超时单位

class webServer {
public:
    webServer();

    ~webServer();

    void init();

    void loop();

private:

};

#endif //SIMPLESERVER_WEBSERVER_H
