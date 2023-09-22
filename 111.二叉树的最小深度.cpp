/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */
#include "heads.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
class Solution {
public:
    //queue ok
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        queue<TreeNode*> que;
        que.push(root);
        int nrow = 1;
        while (!que.empty()) {
            auto sz = que.size();
            for(int i = 0; i < sz; ++ i) {
                auto node = que.front(); 
                que.pop();
                if(!node->left && !node->right)
                    return nrow;
                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
            }
            ++ nrow;
        }
        return nrow;
    }
    //recursion ok
    /*
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int nl = root->left ? 1+minDepth(root->left) : INT_MAX;
        int nr = root->right ? 1+minDepth(root->right) : INT_MAX;
        return min(nl, nr);
    }
    */
};
// @lc code=end

