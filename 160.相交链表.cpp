/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    // 官方思路，两个list遍历有人到尾时，交换p，再相交即为
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB ;
        while (pa && pb && pa!=pb)    pa=pa->next, pb=pb->next ;
        swap (pa, pb) ;
        while (pa != pb) {
            pa = pa ? pa->next : headA ;
            pb = pb ? pb->next : headB ;
        }
        return pa ;
    }

    /*
    // 思路，1. 先遍历得到两个list的长, 2. 得到差c，让长list先跑c次，3. 两list一起跑
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB ;
        int ac = 0, bc = 0, c ;
        // get length of lists
        while (pa || pb) {
            if (pa) pa=pa->next, ++ac ;
            if (pb) pb=pb->next, ++bc ;
        }

        // make longer list run firstly
        pa = headA, pb = headB, c = ac - bc ;
        c = (ac > bc) ? c : (swap(pa, pb), -c) ;
        while (c--) pa=pa->next ;
        // cout << ac << bc << c << endl ;

        // find meed node
        while (pa && pb && (pa != pb))    pa=pa->next, pb=pb->next ;
        return (pa && pb) ? pa : nullptr ;
    }
    */
};
// @lc code=end

