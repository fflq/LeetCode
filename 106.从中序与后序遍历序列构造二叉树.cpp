/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    // 后序的最后一个是分割节点，注意边界处理
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty())  return nullptr ;

        int rootval = postorder.back(); postorder.pop_back() ;
        auto root = new TreeNode(rootval) ;

        int idx = getIdx(inorder, rootval) ;
        if (idx > 0) {
            // 根据rootval分割inorder，取左边，同样postorder取前idx个(对应inorder左)
            auto newin = vector<int>(inorder.begin(), inorder.begin()+idx) ;
            auto newpost = vector<int>(postorder.begin(), postorder.begin()+idx) ;
            root->left = buildTree(newin, newpost) ;
        }   
        if (idx < inorder.size()-1) {
            auto newin = vector<int>(inorder.begin()+idx+1, inorder.end()) ;
            auto newpost = vector<int>(postorder.begin()+idx, postorder.end()) ;
            root->right = buildTree(newin, newpost) ;
        }

        return root ;
    }
    inline int getIdx(vector<int> &vec, int tgt) {
        int idx ;
        for (idx = 0; idx < vec.size(); ++ idx)
            if (vec[idx] == tgt)    break ;
        return idx ;
    }
};
// @lc code=end









