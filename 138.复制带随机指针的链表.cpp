/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#ifdef FLQ
#include "heads.h"
#endif

class Solution {
public:
    unordered_map<Node *, int> srcMap ;
    vector<Node *> dstList ;

    // random要填的是对应索引元素的地址，不是索引
    Node* copyRandomList(Node* head) {
        // 映射src的random地址到索引
        Node *p = head ; int n = 0 ;
        while (p)   srcMap[p]=++n, p = p->next ;    // 索引多加1，避免0和nullptr歧义

        // copy src元素到dst
        p = copyE(head) ;

        // 映射dst的random到实际地址
        random2Addr (p) ;
        
        return p ;
    }

    // 转换dst的索引到地址
    void random2Addr(Node *p) {
        while (p) {
            p->random = p->random ? dstList[(long)(p->random)-1] : nullptr ;    // 索引-1恢复
            p = p->next ;
        }
    }

    // copy元素，并记录索引
    Node *copyE(Node *head) {
        if (head) {
            Node *node = new Node(head->val) ;
            dstList.push_back(node) ;   // before recur
            node->next = head->next ? copyE(head->next) : nullptr ;
            node->random = head->random ? (Node*)srcMap[head->random] : nullptr ;
            return node ;
        }
        return nullptr ;
    }
};
// @lc code=end

