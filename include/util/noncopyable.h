//
// Created by zxj on 2022/5/2.
//

#ifndef SIMPLESERVER_NONCOPYABLE_H
#define SIMPLESERVER_NONCOPYABLE_H

class Noncopyable
{
protected:
    Noncopyable(){}
    ~Noncopyable(){}
private:
    Noncopyable(const Noncopyable&) = delete;
    Noncopyable &operator=(const Noncopyable&) = delete;
};

#endif //SIMPLESERVER_NONCOPYABLE_H
