//
// Created by zxj on 2022/3/21.
//

#ifndef SIMPLESERVER_LOCKER_H
#define SIMPLESERVER_LOCKER_H
#include <pthread.h>
#include <exception>
#include <iostream>
#include <semaphore.h>

#include "../util/noncopyable.h"

//信号量封装类
class sem
{
public:
    sem(){
        if (sem_init(&m_sem, 0, 0) != 0){
            throw std::exception();
        }
    }
    sem(int num)
    {
        if (sem_init(&m_sem, 0, num) != 0)
        {
            throw std::exception();
        }
    }
    ~sem()
    {
        sem_destroy(&m_sem);
    }
    bool wait()
    {
        return sem_wait(&m_sem) == 0;
    }
    bool post()
    {
        return sem_post(&m_sem) == 0;
    }
private:
    sem_t m_sem;
};


//互斥锁封装类
class locker
{
public:
    locker() {
        if (pthread_mutex_init(&m_mutex, NULL) != 0){
            throw std::exception();
        }
    }

    ~locker() {
        pthread_mutex_destroy(&m_mutex);
    }

    bool lock(){
        return pthread_mutex_lock(&m_mutex) == 0;
    }

//    如果目标可以加锁，对目标加锁，不能加锁返回false
//    bool trylock();

    bool unlock(){
        return pthread_mutex_unlock(&m_mutex) == 0;
    }

    pthread_mutex_t *get() {
        return &m_mutex;
    }

private:
    pthread_mutex_t m_mutex;
};

//条件变量封装类
class cond
{
public:
    cond(){
        if (pthread_cond_init(&m_cond, NULL) != 0){
            throw std::exception();
        }
    }

    ~cond(){
        pthread_cond_destroy(&m_cond);
    }

    bool wait(pthread_mutex_t *mutex){
        return pthread_cond_wait(&m_cond, mutex) == 0;
    }

    bool signal(){
        return pthread_cond_signal(&m_cond) == 0;
    }

    bool broadcast(){
        return pthread_cond_broadcast(&m_cond) == 0;
    }

    bool timewait(pthread_mutex_t *mutex, struct timespec t) {
        return pthread_cond_timedwait(&m_cond, mutex, &t);
    }

private:
    pthread_cond_t m_cond;
};

class MutexLockGuard : Noncopyable
{
public:
    explicit MutexLockGuard(locker &_mutex) : mutex(_mutex) { mutex.lock(); }
    ~MutexLockGuard() { mutex.unlock(); }
private:
    locker &mutex;
};

#endif //SIMPLESERVER_LOCKER_H
