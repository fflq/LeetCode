/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#ifdef FLQ
#include "heads.h"
#endif

class Solution {
public:
    Node* connect(Node* root) {
        return connect2(root) ;
    }

    // 官解，使用上层已建好的next
    Node* connect2(Node* root) {
        if (!root || !root->left || !root->right)  return root ;

        root->left->next = root->right ;
        if (root->next)  root->right->next = root->next->left ;

        connect2 (root->left) ;
        connect2 (root->right) ;

        return root ;
    }

    // 常规层次遍历
    Node* connect1(Node* root) {
        if (!root)  return nullptr ;          

        queue<Node *> que ;
        que.push (root) ;

        while (!que.empty()) {
            Node *p = nullptr ;
            int size = que.size() ;
            while (size --) {
                Node *q = que.front() ; que.pop() ;
                if (q->left)    que.push(q->left) ;
                if (q->right)    que.push(q->right) ;
                if (p)  p->next = q ;   // p is nullptr in first
                p = q ;
            }
        }
        return root ;
    }
};
// @lc code=end

