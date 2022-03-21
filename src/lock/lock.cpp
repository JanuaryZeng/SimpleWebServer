//
// Created by zxj on 2022/3/21.
//

#include "../../include/lock/lock.h"

zxj::locker::locker() {
    if (pthread_mutex_init(&__m_mutex,nullptr) != 0)throw std::exception();
}

zxj::locker::~locker() {
    //TODO:是否需要处理异常
    pthread_mutex_destroy(&__m_mutex);
}

bool zxj::locker::lock() {
    return pthread_mutex_lock(&__m_mutex) == 0;
}

//如果目标可以加锁，对目标加锁，不能加锁返回false
bool zxj::locker::trylock() {
    return pthread_mutex_trylock(&__m_mutex) == 0;
}

bool zxj::locker::unlock() {
    return pthread_mutex_unlock(&__m_mutex) == 0;
}

pthread_mutex_t *zxj::locker::get() {
    return &__m_mutex;
}

zxj::cond::cond() {
    if(pthread_cond_init(&__m_cond,nullptr) != 0)
        throw std::exception();
}

zxj::cond::~cond() {
    pthread_cond_destroy(&__m_cond);
}

bool zxj::cond::wait(locker &mutex) {
    return pthread_cond_wait(&__m_cond, mutex.get()) == 0;
}

bool zxj::cond::signal() {
    return pthread_cond_signal(&__m_cond) == 0;
}

//TODO:广播如何做到广播多个
bool zxj::cond::broadcast() {
    return pthread_cond_broadcast(&__m_cond) == 0;
}

bool zxj::cond::timewait(locker &mutex, struct timespec t) {
    return pthread_cond_timedwait(&__m_cond, mutex.get(), &t) == 0;
}