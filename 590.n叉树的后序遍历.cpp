/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#ifdef FLQ
#include "heads.h"
#endif

class Solution {
public:
    vector<int> v ;
    vector<int> postorder(Node* root) {
        od (root) ;
        return v ;
    }

    void od (Node *root) {
        if (!root)  return ;

        for (auto e : root->children)   od(e) ;
        v.push_back (root->val) ;
    }
};
// @lc code=end

