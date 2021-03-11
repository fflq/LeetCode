/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#ifdef FLQ
#include "heads.h"
#endif

class Solution {
public:
    // 寻找公共最远路径
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vp, vq ;
        getPath(root, p, vp), getPath(root, q, vq) ;    // 获取二者路径

        TreeNode *sameRoot = root ;  // 寻找路径公共部分，从后往前
        for (int i = vp.size()-1, j = vq.size()-1; i >= 0 && j >= 0; -- i, -- j)
            if (vp[i] == vq[j])  sameRoot = vp[i] ;
            else    break ;

        return sameRoot ;
    }
    inline bool getPath(TreeNode *root, TreeNode *p, vector<TreeNode*> &v) {
        if (!root)  return false ;
        if (root == p)  return true ;

        if (getPath(root->left, p, v)) {
            v.push_back (root->left) ;
            return true ;
        }
        if (getPath(root->right, p, v)) {
            v.push_back (root->right) ;
            return true ;
        } 
        return false ;
    }
};
// @lc code=end

