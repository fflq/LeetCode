/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#ifdef FLQ
#include "heads.h"
#endif 

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        return rotateRight2(head, k) ;
    }

    // 官方题解方式，连环再割
    ListNode* rotateRight2(ListNode* head, int k) {
        int len = 0 ;
        ListNode *prev = head, *p = head ;

        while (p)   ++len, prev=p, p=p->next ;
        if (prev)   prev->next = head ;
        if (len > 0)    k = len - k % len ;

        p = head ;
        while (k-- && p)   prev=p, p=p->next ;
        if (prev)   prev->next = nullptr ;

        return p ;
    }

    ListNode* rotateRight1(ListNode* head, int k) {
        int len = 0 ;
        ListNode *p = head, *q, *end=head ;
        ListNode *dummy = new ListNode(-1, head), *dp=dummy ;

        // 计算长度和偏移量
        while (p)   ++len, p=p->next ;
        if (len>0)  k = len - k%len ;

        // 移动p到k处
        p = head ;
        while (k-- && p)    end=p, p=p->next ;   
        if(end) end->next = nullptr ;

        // 移动k后到前面
        while (p && p!=head) {  // 避免成环
            q = p->next ;
            p->next = dp->next ;
            dp->next = p ;
            dp = p ;
            p = q ;
        }

        return dummy->next ;
    }
};
// @lc code=end
