/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        //return removeElements1(head, val) ;
        return removeElements2(head, val) ;
    }

    // 带头结点
    ListNode* removeElements2(ListNode* head, int val) {
        head = new ListNode(-1, head) ; // 添加头结点的省略写法

        ListNode *prev = head, *p = head->next ;
        while (p) {
            prev = (p->val == val) ? (deleteE(prev), prev) : p ;
            p = prev->next ;
        }
        return head->next ;
    }

    // 不带头结点，不够优美
    ListNode* removeElements1(ListNode* head, int val) {
        while (head && head->val == val)   head = head->next ;

        if (!head)  return head ;
        ListNode *prev = head, *p = head->next ;
        while (p) {
            if (p->val == val)  deleteE(prev) ;
            else    prev = p ;
            p = prev->next ;
        }
        return head ;
    }
    // no free 
    inline void deleteE(ListNode* prev) { prev->next = prev->next->next ; }

};
// @lc code=end

