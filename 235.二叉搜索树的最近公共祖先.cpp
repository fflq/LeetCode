/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    // 优化，不需要minmax
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val < p->val && root->val < q->val)   return lowestCommonAncestor(root->right, p, q) ;
        if (root->val > p->val && root->val > q->val)   return lowestCommonAncestor(root->left, p, q) ;
        return root ;
    }

    // 关键在于找分叉点(不需要注意min和max,test时写了)
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minv = min(p->val, q->val), maxv = max(p->val, q->val) ;
        // 因为T说明val唯一，故简化处理
        return findSameAnc(root, minv, maxv) ;
    }
    TreeNode *findSameAnc(TreeNode *root, int minv, int maxv) {
        // 二者在root左右，分叉点
        if (root->val >= minv && root->val <= maxv)   return root ;
        // 二者均在root右right
        else if (root->val < minv)   return findSameAnc(root->right, minv, maxv) ;
        else if (root->val > maxv)   return findSameAnc(root->left, minv, maxv) ;
        return root ;
    }

};
// @lc code=end

