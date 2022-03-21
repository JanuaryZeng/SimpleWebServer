//
// Created by zxj on 2022/3/21.
//

#ifndef SIMPLESERVER_LOCK_H
#define SIMPLESERVER_LOCK_H
#include<pthread.h>
#include <exception>
#include <iostream>
namespace zxj {
//互斥锁封装类
class locker {
public:
    locker();

    ~locker();

    bool lock();

    //如果目标可以加锁，对目标加锁，不能加锁返回false
    bool trylock();

    bool unlock();

    pthread_mutex_t *get();

private:
    pthread_mutex_t __m_mutex;
};

//条件变量封装类

class cond {
public:
    cond();

    ~cond();

    bool wait(locker &mutex);

    bool signal();

    bool broadcast();

    bool timewait(locker &mutex, struct timespec t);

private:
    pthread_cond_t __m_cond;
};

}
#endif //SIMPLESERVER_LOCK_H
