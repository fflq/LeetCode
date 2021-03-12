/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        return isPalindrome2(head) ;
    }

    // 不用遍历求长，用快慢指针
    bool isPalindrome2(ListNode* head) {
        // 找到一半，可用快慢指针
        ListNode *slow = head, *fast = head ;
        while (fast) {
            slow = slow->next ;
            fast = fast->next ? fast->next->next : fast->next ;   // 判断放这，是为了多一次循环
        }

        // 头插法后一半
        ListNode *dummy = new ListNode, *p = slow, *q ;
        while (p) {
            q = p->next ;
            p->next = dummy->next ;
            dummy->next = p ;
            p = q ;
        }    

        // 比较两段
        p = head, q = dummy->next ;
        while (p && q) {
            if (p->val != q->val)   return false ;
            p = p->next ;
            q = q->next ;
        }

        return true ;
    }

    bool isPalindrome1(ListNode* head) {
        int n = 0, len=0 ;
        ListNode *p = head, *q=head ;
        while (p)   ++len, p=p->next ;

        // 找到一半，可用快慢指针
        n = len/2 + len%2 ;
        while (n-- && q) q=q->next ;
        p = q ;

        // 头插法后一半
        ListNode *dummy = new ListNode ;
        while (p) {
            q = p->next ;
            p->next = dummy->next ;
            dummy->next = p ;
            p = q ;
        }    

        // 比较两段
        n = len/2 ;
        p = head, q = dummy->next ;
        while (n--) {
            if (p->val != q->val)   return false ;
            p = p->next ;
            q = q->next ;
        }
        return true ;
    }
};
// @lc code=end

