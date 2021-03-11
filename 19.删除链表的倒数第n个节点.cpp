/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    // 思路，p先走n次，然后p和pn同步走到p为空，此时pn即为倒数第n
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *pn = head, *pn_prev=nullptr ;
        while (n--) p = p->next ;   
        while (p)   p=p->next, pn_prev=pn, pn=pn->next ;

        if (pn_prev)    pn_prev->next = pn->next ;  // 倒数第n是否有前驱，无则表示为head
        else    head = pn->next ;
        delete pn ;

        return head ;
    }
};
// @lc code=end

