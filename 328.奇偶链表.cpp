/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    // 用listhead那样串起来就行
    ListNode* oddEvenList(ListNode* head) {
        bool isOdd = true ;
        ListNode *odd = new ListNode, *even = new ListNode ;
        ListNode *p = head, *q, *oddp = odd, *evenp = even ; 
        while (p) {                
            q = p; 
            p = p->next ;

            if (isOdd) {    // 添加到奇数列
                oddp->next = q ;
                oddp = oddp->next ;
            }
            else {  // 添加到偶数列
                evenp->next = q ;
                evenp = evenp->next ;
            }

            isOdd = !isOdd ;
        }
        evenp->next = nullptr ;
        oddp->next = even->next ;   // 连接奇偶数列：奇尾连偶头

        return odd->next ;
    }
};
// @lc code=end

