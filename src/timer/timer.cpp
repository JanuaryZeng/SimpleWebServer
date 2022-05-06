//
// Created by zxj on 2022/5/2.
//

#include "../../include/timer/timer.h"

bool TimeHeap::add_timer(std::shared_ptr<heap_timer> timer) {
    if(!timer)
        return false;
    if(curr_size >= capactity) {
        tick();
        assert(curr_size < capactity);
    }
    int hole = curr_size++;
    array[hole] = timer;
    array[hole]->hole_ = hole;
    percolate_up(hole);
    return true;
}

bool TimeHeap::del_timer(std::shared_ptr<heap_timer> timer) {
    if(!timer){
        return false;
    }
    mutex.lock();
    overtimer.push_back(timer->hole_);
    mutex.unlock();
    timer->cb_func = nullptr;
    timer->user_data.reset();
    return true;
}

void TimeHeap::pop_timer() {
    if(empty())
        return;
    if(array[0]){
        array[0] = array[--curr_size];
        array[0]->hole_ = 0;
        percolate_down(0);
    }
}

bool TimeHeap::adjustTimer(std::shared_ptr<heap_timer> timer, int delay) {
    if (!timer){
        return false;
    }
    timer->expire = time(NULL)+delay;
    if(delay > 0){
        percolate_down(timer->hole_);
    }
    else{
        percolate_up(timer->hole_);
    }
    return true;
}

void TimeHeap::tick() {
    time_t cur = time(NULL);
    adjust();
    while(!empty()){
        if(!array[0]){
            pop_timer();
            continue;
        }
        if(array[0]->expire > cur){
            break;
        }
        if(array[0]->cb_func){
            array[0]->cb_func(array[0]->user_data.lock());
        }
        pop_timer();
    }
}

void TimeHeap::percolate_up(int hole) {
    std::shared_ptr<heap_timer> tmp = array[hole];
    int parent = 0;
    for (; hole > 0; hole = parent)
    {
        parent = (hole - 1) / 2;
        if (array[parent]->expire <= tmp->expire)
        {
            break;
        }
        array[hole] = array[parent];
        array[hole]->hole_ = hole;
    }
    array[hole] = tmp;
    array[hole]->hole_ = hole;
}

void TimeHeap::percolate_down(int hole) {
    std::shared_ptr<heap_timer> tmp = array[hole];
    int child = hole*2+1;
    for (; (hole*2+1) <= curr_size - 1; hole = child){
        if(child + 1 <= curr_size - 1 && array[child+1]->expire > array[child]->expire){
            child++;
        }
        if(array[child]->expire < array[hole]->expire){
            array[hole] = array[child];
            array[hole]->hole_ = hole;
        }
        child = hole*2-1;
    }
    array[hole] = tmp;
    array[hole]->hole_ = hole;
}


void TimeHeap::adjust(){
    mutex.lock();
    std::vector<int> tmp(overtimer);
    overtimer.clear();
    mutex.unlock();
    for (const auto i:tmp)
    {
        if (nullptr == array[i]->cb_func)
        {
            array[i]->expire = 0;
            percolate_up(i);
        }
    }
}