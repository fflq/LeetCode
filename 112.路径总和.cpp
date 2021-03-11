/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSum1(root, targetSum) ;
    }

    // 自顶向下
    bool hasPathSum1(TreeNode* root, int tgt) {
        if (!root) return false ;    
        // ||的提前返回相当于剪枝了，不用单独变量bool isHave来剪枝
        return (!root->left && !root->right && root->val == tgt) 
                || hasPathSum1 (root->left, tgt - root->val) 
                || hasPathSum1 (root->right, tgt - root->val) ;
    }

};
// @lc code=end












