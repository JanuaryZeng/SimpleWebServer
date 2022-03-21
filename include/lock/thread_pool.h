//
// Created by zxj on 2022/3/21.
//

#ifndef SIMPLESERVER_THREAD_POOL_H
#define SIMPLESERVER_THREAD_POOL_H

#include <thread_db.h>
#include <vector>
#include <memory>
#include <cstdio>
#include <list>
#include "lock.h"
namespace zxj {

const int MIN_THREAD_NUM = 1;
const int MAX_THREAD_NUM = 1024;

template<typename T>
class threadpool {
public:
    /*thread_number是线程池中的线程数量，max_requests是请求队列中对多允许的，等待处理的请求数量*/
    threadpool(int thread_number, int max_requests);

    ~threadpool();
    //TODO:shared_ptr unique_ptr区别
    bool append(std::shared_ptr<T> request);

private:
    /*工作线程运行的函数，它不断从工作队列中去除任务并执行之*/
    static void *worker(void *arg);
    void run();

private:
    int __m_thread_number;
    int __m_max_requests;
    std::vector<thread_t> __m_threads;
    std::list<std::shared_ptr<T>> __work_queue;
    locker __queue_locker;
    cond __not_empty;
    cond __not_full;
    bool __stop = false;
};

}
#endif //SIMPLESERVER_THREAD_POOL_H
