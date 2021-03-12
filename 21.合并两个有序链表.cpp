/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1, nullptr) ;
        ListNode *p = dummy, *q ;
        while (l1 && l2) {
            (l1->val < l2->val) ? (q=l1, l1=l1->next) : (q=l2, l2=l2->next) ;   // 不加括号会出错
            q->next = p->next ;
            p->next = q ;
            p = q ;
        }
        p->next = l1 ? l1 : l2 ;    // 剩余

        return dummy->next ;
    }
};
// @lc code=end

