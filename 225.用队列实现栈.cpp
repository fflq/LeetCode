/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class MyStack {
public:
    // 思路，因为stack是LIFO，故用于pop的queue总是要保证最多只有一个元素
    // 从而另一个queue要保证pop的LIFO顺序，方法只能是不断切换两个队列作用
    // 切换过程中要保持in为空，所以in的元素转移到out后
    // in[a,x]表示本轮push(x)是在该que来in的
    // [],[] => in[1],[] => [1],in[2] => in[3],[2,1] => [3,2,1],in[4]
    // out时，若连续pop时，out队列为空，则不切换
    // out3[2,1],[4] => out2[1],[4] => [1,4],in[5] => out1[4],[5] => out4[],[5] => [],out5[]
    queue<int> que1, que2 ;
    queue<int> *queIn = &que1, *queOut = &que2 ;    // 不可用引用

    /** Initialize your data structure here. */
    MyStack() { }

    // 将queSrc全部转移到queDst中
    void transfer(queue<int> *queSrc, queue<int> *queDst) {
        while (!queSrc->empty())  queDst->push(queSrc->front()), queSrc->pop() ;
    }
    
    /** Push element x onto stack. */
    void push(int x) {  // 确保queIn是空的再push，不空则放到out后面
        if (!queIn->empty()) transfer(queIn, queOut) ;   // 保持out最上面是最新的
        queIn->push(x) ;
        swap (queIn, queOut) ;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() { return flqpeek(true) ; }

    int flqpeek(bool ifPop = false) {
        int x = queOut->front() ;   // 题意都是合理操作，不用考虑空
        if (ifPop) {
            queOut->pop() ;
            if (queOut->empty())    swap(queIn, queOut) ;   // out出完才到in出
        }  
        return x ;
    }
    
    /** Get the top element. */
    int top() { return flqpeek() ; }
    
    /** Returns whether the stack is empty. */
    bool empty() { return que1.empty() && que2.empty() ; }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

