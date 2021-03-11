/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        //return isSymmetric1(root) ;
        return isSymmetric2(root) ;
    }

    // me，root->left用根左右得v1，root->right用根右左得v2，比较二者
    bool isSymmetric1(TreeNode *root) { return true ; }

    // 官方题解，两个指针动态比较，me法要生成所有才比，效率不高
    bool isSymmetric2(TreeNode *root) {
        if (!root)  return true ;
        return comp(root->left, root->right) ;
    }
    bool comp(TreeNode *left, TreeNode *right) {
        if (!left && !right)    return true ;
        if (!left || !right)    return false ;  // 有一空
        // 以层次的方式往下比较
        return (left->val == right->val) && comp(left->left, right->right) && comp(left->right, right->left) ;
    }
};
// @lc code=end

