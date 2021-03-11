/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class MyQueue {
public:
    stack<int> stin, stout ;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stin.push (x) ;
    }

    // 仅stout空时可转移，将stin数据全出栈装到stout中,此时stin空了
    void transfer() {
        if (stout.empty()) {    
            while (!stin.empty())   
                stout.push (stin.top()), stin.pop() ;
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = peek() ;
        return x==-1 ? x : (stout.pop(), x) ;
    }
    
    /** Get the front element. */
    int peek() {
        transfer () ;
        return stout.empty() ? -1 : stout.top() ;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stin.empty() && stout.empty() ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

