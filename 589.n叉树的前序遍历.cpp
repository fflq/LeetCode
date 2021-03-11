/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
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
    vector<int> preorder(Node* root) {
        od (root) ;
        return v ;
    }

    void od (Node *root) {
        if (!root)  return ;

        v.push_back (root->val) ;
        for (auto e : root->children)   od(e) ;
    }   

};
// @lc code=end

