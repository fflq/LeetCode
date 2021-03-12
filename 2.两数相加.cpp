/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    int getVal(ListNode *p) {
        return p ? p->val : 0 ;
    }

    ListNode *getNext(ListNode *p) {
        return p ? p->next : nullptr ;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2 ;
        ListNode *l = nullptr, *p = nullptr ;
        int v1, v2, v, cf=0 ;
        bool isFirst = true ;

        while (true) {
            v1 = getVal(p1) ;
            v2 = getVal(p2) ;
            v = v1 + v2 + cf ;
            cf = v / 10 ;
            v = v % 10 ;

            if (isFirst) {
                l = p = new ListNode(v) ;
                isFirst = false ;
            }
            else {
                p->next = new ListNode(v) ;
                p = p->next ;
            }

            p1 = getNext(p1) ;
            p2 = getNext(p2) ;
            if (!p1 && !p2 && cf==0)   break ;
        }

        return l ;
    }
};
// @lc code=end

