//
// Created by zxj on 2022/3/21.
//

#ifndef SIMPLESERVER_LOCK_H
#define SIMPLESERVER_LOCK_H
#include <pthread.h>
#include <exception>
#include <iostream>
#include <semaphore.h>

//信号量封装类
class sem
{
public:
    sem(){
        if (sem_init(&__m_sem, 0, 0) != 0){
            throw std::exception();
        }
    }
    sem(int num)
    {
        if (sem_init(&__m_sem, 0, num) != 0)
        {
            throw std::exception();
        }
    }
    ~sem()
    {
        sem_destroy(&__m_sem);
    }
    bool wait()
    {
        return sem_wait(&__m_sem) == 0;
    }
    bool post()
    {
        return sem_post(&__m_sem) == 0;
    }
private:
    sem_t __m_sem;
};


//互斥锁封装类
class locker
{
public:
    locker() {
        if (pthread_mutex_init(&__m_mutex, NULL) != 0){
            throw std::exception();
        }
    }

    ~locker() {
        pthread_mutex_destroy(&__m_mutex);
    }

    bool lock(){
        return pthread_mutex_lock(&__m_mutex) == 0;
    }

//    如果目标可以加锁，对目标加锁，不能加锁返回false
//    bool trylock();

    bool unlock(){
        return pthread_mutex_unlock(&__m_mutex) == 0;
    }

    pthread_mutex_t *get() {
        return &__m_mutex;
    }

private:
    pthread_mutex_t __m_mutex;
};

//条件变量封装类
class cond
{
public:
    cond(){
        if (pthread_cond_init(&__m_cond, NULL) != 0){
            throw std::exception();
        }
    }

    ~cond(){
        pthread_cond_destroy(&__m_cond);
    }

    bool wait(pthread_mutex_t *mutex){
        return pthread_cond_wait(&__m_cond, mutex) == 0;
    }

    bool signal(){
        return pthread_cond_signal(&__m_cond) == 0;
    }

    bool broadcast(){
        return pthread_cond_broadcast(&__m_cond) == 0;
    }

    bool timewait(pthread_mutex_t *mutex, struct timespec t) {
        return pthread_cond_timedwait(&__m_cond, mutex, &t);
    }

private:
    pthread_cond_t __m_cond;
};


#endif //SIMPLESERVER_LOCK_H
