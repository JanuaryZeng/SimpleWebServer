//
// Created by zxj on 2022/5/2.
//

#ifndef SIMPLESERVER_TIMER_H
#define SIMPLESERVER_TIMER_H

#include <time.h>
#include <memory>
#include <cassert>
#include <vector>
#include "../lock/lock.h"

class http_conn;

/*
    定时器类
    与http_conn类使用weak_ptr相互指向
    避免shared_ptr循环引用造成无法释放
    cb_func  ：定时器超时时调用的函数
    expire   ：定时器的到期时间  绝对时间
    user_data：指向定时器归属与那个用户
    hole_    ：用于在时间堆中调制
*/

class heap_timer
{
public:
    heap_timer(int delay){
        expire = time(NULL) + delay;
        hole_ = -1;
        user_data.reset();
        cb_func = nullptr;
    }
    time_t expire;
    void (*cb_func)(std::shared_ptr<http_conn>);
    std::weak_ptr<http_conn> user_data;
    int hole_;
};

/*
    时间堆类
    以vector为基础数据机构实现的一个时间堆
    删除使用延迟删除策略，删除时仅是将定时器中的cb_func

    线程不安全
*/

class TimeHeap
{
public:
    TimeHeap(int cap) : capactity(cap), cur_size(0){
        array.assign(cap, nullptr);
    }
    bool add_timer(std::shared_ptr<heap_timer> timer);
    bool del_timer(std::shared_ptr<heap_timer> timer);
    std::shared_ptr<heap_timer> top() const{
        if(empty()){
            return nullptr;
        }
        return array[0];
    }
    void pop_timer();
    void tick();
    bool adjustTimer(std::shared_ptr<heap_timer> timer, int delay);
    bool empty() const {return cur_size == 0;}
    bool size() const {return cur_size;}
private:
    void percolate_down(int hole);//下滤操作
    void percolate_up(int hole);//上滤操作

    std::vector<int> overtimer;
    locker mutex;
    void adjust();
    std::vector<std::shared_ptr<heap_timer>> array;
    int capactity;
    int cur_size;
};

#endif //SIMPLESERVER_TIMER_H
