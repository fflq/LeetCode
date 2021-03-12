/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = head, *end = head, *p ;
        while (end && end->next)    end = end->next ;
        while (newHead != end) {
            p = newHead ;
            newHead = newHead->next ;
            p->next = end->next ;
            end->next = p ;
        }
        return end ;
    }
};
// @lc code=end

