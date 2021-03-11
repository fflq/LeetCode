/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root)  return 0 ;
        int va = root->val ;

        if (va < low)    return rangeSumBST(root->right, low, high) ;
        if (va > high)   return rangeSumBST(root->left, low, high) ;

        return va + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high) ; ;
    }
};
// @lc code=end

