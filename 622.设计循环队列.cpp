/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class MyCircularQueue {
private :
    int *data, size, front, rear ;
public:
    MyCircularQueue(int k) {
        size = k + 1 ;  // 多一个空间，用于区分空和满
        data = new int[size] ;
        front = rear = 0 ;
    }
    
    bool enQueue(int value) {
        if (isFull())   return false ;
        rear = (rear+1) % size ;
        data[rear] = value ;
        return true ;
    }
    
    bool deQueue() {
        if (isEmpty())  return false ;
        front = (front+1) % size ;
        return true ;
    }
    
    int Front() {
        return isEmpty() ? -1 : data[(front+1)%size] ;
    }
    
    int Rear() {
        return isEmpty() ? -1 : data[rear] ;
    }
    
    bool isEmpty() {
        return front == rear ;
    }
    
    bool isFull() {
        return front == (rear+1)%size ;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

