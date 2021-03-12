/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
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
    // 这题有点意思
    void deleteNode(ListNode* node) {
        node->val = node->next->val ;
        node->next = node->next->next ;
    }
    void deleteNode1(ListNode* node) {
        ListNode *p = node, *pp = p ;
        while (p->next) {
            p->val = p->next->val ;
            pp = p ;
            p = p->next ;
        }
        pp->next = nullptr ;
    }
};
// @lc code=end

