/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        //return isBalanced1(root) ;
        return isBalanced2(root) ;
    }

    // 法2
    bool isBal = true ;
    bool isBalanced2(TreeNode* root) {
        getHight(root) ;
        return isBal ; 
    }
    int getHight(TreeNode *root) {
        if (!isBal || !root) return 0 ;    // !isBal已经找到不平衡了，提前返回

        int lh = getHight(root->left), rh = getHight(root->right) ;
        isBal = isBal && (abs(lh-rh) <= 1) ;
        return max(lh, rh) + 1 ; 
    }

    // 法1
    bool isBalanced1(TreeNode* root) {
        int height ;
        return calBal(root, height) ;
    }
    bool calBal(TreeNode *root, int &height) {
        if (!root) { height = 0; return true ; }    // 叶子

        int lh, rh ;
        bool ret = calBal(root->left, lh) && calBal(root->right, rh) ;  // 左右各子树是否平衡
        height = max(lh, rh)+1 ;    // 当前高度

        if (!ret)   return false ;  // 左右子树有不平衡
        else if (abs(lh-rh) > 1)    return false ;  // 左右各子树平衡但root不平衡

        return  true ; 
    }
};
// @lc code=end

