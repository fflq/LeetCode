/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */
#include "heads.h"

// @lc code=start
class MyLinkedList {
public:
    // 带头结点
    int val ;
    MyLinkedList *next ;

    /** Initialize your data structure here. */
    MyLinkedList(): MyLinkedList(-1) {
    }

    MyLinkedList(int val, MyLinkedList *next=nullptr): val(val), next(next) {
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        auto p = this->next ;
        while (index-- && p)    p = p->next ;
        return p ? p->val : -1 ;
    }

    MyLinkedList *getItem(int index) {
        auto p = this->next ;
        if (index < 0)  return nullptr ;
        else {
            while (index-- && p)    p = p->next ;
            return p ;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto e = new MyLinkedList(val, this->next) ;
        this->next = e ;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto p = this ;
        while (p->next) p = p->next ;
        p->next = new MyLinkedList(val) ;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index <= 0) addAtHead(val) ;
        else {
            auto p = this ;
            while (index-- && p) p = p->next ;
            if (index < 0) p->next = new MyLinkedList(val, p->next) ;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        MyLinkedList *p = nullptr, *q = nullptr ;
        if (index == 0) p = this ;
        else if (index > 0) p = getItem(index-1) ; // find prev node of del-node

        if (p && p->next) {
            auto q = p->next ;
            p->next = q->next ;
            delete q ;
        }
    }

    void output(string str="") {
        auto p = this->next ;
        cout << str << ": " ;
        while (p) {
            cout << p->val << ", " ;
            p = p->next ;
        }
        cout << endl ;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

