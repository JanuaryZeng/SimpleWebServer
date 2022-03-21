//
// Created by zxj on 2022/3/21.
//

#include "../../include/lock/thread_pool.h"

template <typename T>
zxj::threadpool<T>::threadpool(int thread_number, int max_requests) : __m_thread_number(thread_number), __m_max_requests(max_requests) {
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
    }
}

template <typename T>
zxj::threadpool<T>::~threadpool<T>() {
    __stop = true;
}

template <typename T>
bool zxj::threadpool<T>::append(std::shared_ptr<T> request) {
    __queue_locker.lock();

    while( __work_queue.size() == __m_max_requests){
        __not_full.wait(__queue_locker);
    }
    __work_queue.push_back(request);
    __queue_locker.unlock();
    __not_empty.signal();
}


template <typename T>
void* zxj::threadpool<T>::worker(void *arg) {
    threadpool<T> *pool = (threadpool<T>*)arg;
    pool->run();
    return pool;
}

template <typename T>
void zxj::threadpool<T>::run() {
    while(!__stop){
        __queue_locker.lock();
        while(__work_queue.empty()){
            __not_empty.wait(__queue_locker);
        }
        std::shared_ptr<T> curr = __work_queue.front();
        __work_queue.pop_front();
        __queue_locker.unlock();
        __not_full.signal();
        curr->run();
    }
}
