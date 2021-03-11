/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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

class Solution {
public:
    // 根据LC106改
    Node* connect(Node* root) {
        //return connect1(root) ;
        return connect2(root) ;
    }

    // 官解，使用上层已建好的next
    Node* connect2(Node* root) {
        if (!root || (!root->left && !root->right))  return root ;

        // 至少有一个不为空，next存root下的最右
        Node *p = root, *&next = root->right ? root->right : root->left ;
        if (root->left)  root->left->next = root->right ;

        // 跨度大，[1,2,3,4,5,null,6,7,null,null,null,null,8]
        while (p->next && !p->next->left && !p->next->right)    p = p->next ;
        if (p->next)  next->next = p->next->left ? p->next->left : p->next->right ;

        connect2 (root->right) ;  // right要优先，因为类似dfs，不然上面while向右会找不到
        connect2 (root->left) ;

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

