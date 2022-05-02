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
    int m_thread_number;
    int m_max_requests;
    std::vector<thread_t> m_threads;
    std::list<std::shared_ptr<T>> work_queue;
    locker queue_locker;
    cond not_empty;
    cond not_full;
    bool stop = false;
};


template <typename T>
threadpool<T>::threadpool(int thread_number, int max_requests) : m_thread_number(thread_number), m_max_requests(max_requests) {
    if(thread_number <= 0 || max_requests <= 0){
        //TODO:打印日志
        throw std::exception();
    }
    m_thread_number = std::min(m_thread_number, MAX_THREAD_NUM);
    for(int i = 0; i < m_thread_number; ++i){
        pthread_t tid;
        if(pthread_create(&tid, nullptr, worker, this) != 0){
            throw std::exception();
        }
        if(pthread_detach(tid)){
            throw std::exception();
        }
        m_threads.push_back(tid);
        printf("%d线程被创建\n",i);
    }
}

template <typename T>
threadpool<T>::~threadpool<T>() {
    stop = true;
}

template <typename T>
bool threadpool<T>::append(std::shared_ptr<T> request) {
    queue_locker.lock();

    while( work_queue.size() == m_max_requests){
        not_full.wait(queue_locker.get());
    }
    work_queue.push_back(request);
    queue_locker.unlock();
    not_empty.signal();
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
    while(!stop){
        queue_locker.lock();
        while(work_queue.empty()){
            not_empty.wait(queue_locker.get());
        }
        std::shared_ptr<T> curr = work_queue.front();
        work_queue.pop_front();
        queue_locker.unlock();
        not_full.signal();
        curr->run();
//        printf("***********************************");
    }
}

#endif //SIMPLESERVER_THREAD_POOL_H
