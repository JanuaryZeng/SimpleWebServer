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
#include "../lock/lock.h"

const int MIN_THREAD_NUM = 1;
const int MAX_THREAD_NUM = 1024;

template<typename T>
class threadpool {
public:
    /*thread_number是线程池中的线程数量，max_requests是请求队列中对多允许的，等待处理的请求数量*/
    threadpool(int thread_number = 5, int max_requests = MAX_THREAD_NUM);

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


template <typename T>
threadpool<T>::threadpool(int thread_number, int max_requests) : __m_thread_number(thread_number), __m_max_requests(max_requests) {
    if(thread_number <= 0 || max_requests <= 0){
        //TODO:打印日志
        throw std::exception();
    }
    __m_thread_number = std::min(__m_thread_number, MAX_THREAD_NUM);
    for(int i = 0; i < __m_thread_number; ++i){
        pthread_t tid;
        if(pthread_create(&tid, nullptr, worker, this) != 0){
            throw std::exception();
        }
        if(pthread_detach(tid)){
            throw std::exception();
        }
        __m_threads.push_back(tid);
        printf("%d线程被创建\n",i);
    }
}

template <typename T>
threadpool<T>::~threadpool<T>() {
    __stop = true;
}

template <typename T>
bool threadpool<T>::append(std::shared_ptr<T> request) {
    __queue_locker.lock();

    while( __work_queue.size() == __m_max_requests){
        __not_full.wait(__queue_locker.get());
    }
    __work_queue.push_back(request);
    __queue_locker.unlock();
    __not_empty.signal();
    //TODO:返回值
    return true;
}


template <typename T>
void* threadpool<T>::worker(void *arg) {
    threadpool<T> *pool = (threadpool<T>*)arg;
    pool->run();
    return pool;
}

template <typename T>
void threadpool<T>::run() {
    while(!__stop){
        __queue_locker.lock();
        while(__work_queue.empty()){
            __not_empty.wait(__queue_locker.get());
        }
        std::shared_ptr<T> curr = __work_queue.front();
        __work_queue.pop_front();
        __queue_locker.unlock();
        __not_full.signal();
        curr->run();
//        printf("***********************************");
    }
}

#endif //SIMPLESERVER_THREAD_POOL_H
