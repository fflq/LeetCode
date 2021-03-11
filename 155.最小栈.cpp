/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class MinStack {
public:
    // 关键，getMin的O1官方思路，辅助容器，记录当前top下min，因为栈的特性
    static const int MAX_SIZE = 10000 ;
    int stack[MAX_SIZE], minstack[MAX_SIZE] ;
    int tp, mintp ;

    /** initialize your data structure here. */
    MinStack() {
        tp = mintp = -1 ;
        minstack[++mintp] = INT_MAX ;
    }
    
    void push(int x) {  
        stack[++tp] = x ;
        int minx = min(minstack[mintp], x) ;
        minstack[++mintp] = minx ;
        //if (++tp >= stack.size())    stack.push_back (x) ;
        //else    stack[tp] = x ;
    }
    
    void pop() {
        if (!empty())   -- tp, -- mintp ;
    }
    
    int top() {
        return empty() ? -1 : stack[tp] ;
    }
    
    int getMin() {
        if (empty())    return -1 ;
        return minstack[mintp] ;
    }

    bool empty() { return tp==-1 ; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

