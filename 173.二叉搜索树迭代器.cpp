/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#ifdef FLQ
#include "heads.h"
#endif
class BSTIterator {
public:
    // 官解的O(h)
    stack<TreeNode *> st ;
    BSTIterator(TreeNode *root) {
        pushLeft (root) ;
    }
    void pushLeft(TreeNode *root) {
        while (root)    st.push (root), root = root->left ;
    }
    int next() {
        auto root = st.top(); st.pop() ;    // 题意不用考虑空
        pushLeft (root->right) ;
        return root->val ;
    }
    bool hasNext() { return !st.empty(); }


    /* 正确的O(n)空间写法
    vector<int> vec ;
    int idx ;
    BSTIterator(TreeNode* root) {
        inorder (root) ;
        idx = 0 ;
    }
    void inorder(TreeNode *root) {
        if (!root)  return ;
        inorder (root->left) ;
        vec.push_back (root->val) ;
        inorder (root->right) ;
    }
    int next() { return vec[idx++] ; // 题意不用考虑空 }
    bool hasNext() { return idx<vec.size() ; }
    */
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

