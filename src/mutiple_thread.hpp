//
// Created by zilch on 2020/9/20.
//

#ifndef INTERVIEW_PROGRAMMING_MUTIPLE_THREAD_HPP
#define INTERVIEW_PROGRAMMING_MUTIPLE_THREAD_HPP
#include "../includes/base_include.h"

std::mutex mtx; // 全局互斥锁.
std::condition_variable cv; // 全局条件变量.
bool ready = false; // 全局标志位.

void do_print_id(int id)
{
    std::unique_lock <std::mutex> lck(mtx);
    while (!ready)
        //cout << "阻塞中 " << id << endl;
        cv.wait(lck);
    std::cout << "thread " << id << '\n';
}

void go()
{
    std::unique_lock <std::mutex> lck(mtx);
    ready = true;
    cv.notify_all();
}


#endif //INTERVIEW_PROGRAMMING_MUTIPLE_THREAD_HPP
