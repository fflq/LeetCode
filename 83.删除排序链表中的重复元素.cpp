/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */
#include "heads.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    //fflq
    static ListNode* createFromList(initializer_list<int> &&vs) {
        ListNode *head = nullptr, *p;
        for(auto &v : vs) {
            if (!head) {
                head = new ListNode(v); 
                p = head;
            }
            else {
                p->next = new ListNode(v);
                p = p->next ;
            }
        }
        return head;
    }

    static void printListNode(ListNode *head) {
        while (head) {
            cout << head->val << "->";
            head = head->next ;
        }
        cout << endl;
    }
};

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
    void reconnDuplicatesRanges(ListNode* &first_same, ListNode* &last_same) {
        if (first_same && last_same) {
            first_same->next = last_same->next ;
            first_same = last_same->next;
            last_same = first_same ;
        }
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head, *first_same = head, *last_same = head;
        while (p) {
            if (p->val == last_same->val) { //foreach
                last_same = p;
            }
            else { //delete
                reconnDuplicatesRanges(first_same, last_same);
            }
            p = p->next;
        }
        reconnDuplicatesRanges(first_same, last_same);
        return head;
    }
};
// @lc code=end

int main() {
    Solution sol;
    ListNode::printListNode(sol.deleteDuplicates(ListNode::createFromList({})));
    ListNode::printListNode(sol.deleteDuplicates(ListNode::createFromList({1,1,2})));
    ListNode::printListNode(sol.deleteDuplicates(ListNode::createFromList({1,1,2,3,3})));
    return 0;
}
