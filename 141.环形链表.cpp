/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    // 1. 首先想到标记，但是ListNode不可改，则可用额外数组记录地址
    // 2. 进阶需O1，则可把1中的数组变为bit数组即可
    // 3. 题解的快慢指针更妙，如下

    // 按照跑步模型优化，之前写法有问题收敛慢，不能只比较fast和slow，沿途也要比
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head?head->next:nullptr ; // fast先跑，避免起点相同情况
        while (fast && fast->next) {
            if (slow == fast || slow == fast->next)   return true ;
            slow = slow->next ;
            fast = fast->next->next ;
        }
        return false ;
    }

    /*
    // 两指针速度>45%，三指针速度>91%，不够还可以继续加
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head, *faster=head ;
        while (slow && fast && faster) {
            slow = slow->next ;
            if (!(fast->next))  return false ;
            fast = fast->next->next ;
            if (!(faster->next) || !(faster->next->next))   return false ;
            faster = faster->next->next->next ;
            if (slow == fast || slow == faster || fast == faster)   return true ;
        }
        return false ;
    }
    */
    /* 两指针速度>45%
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head ;
        while (slow && fast) {
            slow = slow->next ;
            if (!(fast->next))  return false ;
            fast = fast->next->next ;
            if (slow == fast)   return true ;
        }
        return false ;
    }
    */
};
// @lc code=end

