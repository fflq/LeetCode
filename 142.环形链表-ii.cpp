/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    // 不会，以下为官方思路实现，另外本题有公式证明，故不可用fast先跑版/沿途版
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast=head, *p=head ;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next ;
            fast = fast->next->next ;
            if (slow == fast) { // 必须是正好相等
                while (p != slow)   p=p->next, slow=slow->next ;
                return p ;
            }
        }
        return nullptr ;
    }
};
// @lc code=end

