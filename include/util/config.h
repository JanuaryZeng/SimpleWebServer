//
// Created by zxj on 2022/5/2.
//

#ifndef SIMPLESERVER_CONFIG_H
#define SIMPLESERVER_CONFIG_H

#include <string>
#include "../../include/log/logger.h"

class Config
{
public:
    Config();
    ~Config(){};

    void parse_arg(int argc, char *argv[]);
    void parse_ini_file(std::string filename);

    //端口号
    int port;

    //优雅关闭链接
    int linger;

    //线程池内的线程数量
    int thread_num;

    //请求队列中最大请求数量
    int max_request;

    //数据库连接池数量
    int mysql_conn_num;
    std::string mysql_host;
    std::string mysql_user;
    std::string mysql_passwd;
    std::string mysql_db_name;
    int mysql_port;

    //是否关闭日志
    int close_log;
    LOGLEVEL log_level;
    std::string log_pre_filename;
    size_t log_buf_size;
    size_t log_max_lines;

private:
    bool parse_line(std::string line,std::string &key,std::string &val);
    void trim(std::string &str);
};

#endif //SIMPLESERVER_CONFIG_H
