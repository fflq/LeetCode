/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST1(nums) ;
        //return sortedArrayToBST2(nums) ;
    }


    // 练习avl写法（算了，c++不好扩展类，加不了height变量)
    TreeNode* sortedArrayToBST2(vector<int>& nums) {
        TreeNode *root = nullptr ;
        for (auto e : nums)  insertAVL(root, e) ;
        return root ;
    }
    void insertAVL(TreeNode *&root, int e) {
        if (!root)  root = new TreeNode(e) ;
        else if (e < root->val) insertAVL(root->left, e) ;
        else insertAVL(root->right, e) ;
    }


    // 二分写法
    TreeNode* sortedArrayToBST1(vector<int>& nums) {
        return tobst(nums, 0, nums.size()-1) ;
    }
    TreeNode *tobst(vector<int> &nums, int beg, int end) {
        if (beg > end)  return nullptr ;
        int mid = (beg + end) / 2 ;
        return new TreeNode(nums[mid], tobst(nums, beg, mid-1), tobst(nums, mid+1, end)) ;
    }
};
// @lc code=end

