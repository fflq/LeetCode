/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    // 根据106中+后，改的速A（原理同，深究的话参考106）
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())  return nullptr ;

        int rootval = preorder.front(); 
        preorder.erase(preorder.begin()) ;  // 改1
        auto root = new TreeNode(rootval) ;

        int idx = getIdx(inorder, rootval) ;
        if (idx > 0) {
            // 根据rootval分割inorder，取左边，同样postorder取前idx个(对应inorder左)
            auto newin = vector<int>(inorder.begin(), inorder.begin()+idx) ;
            auto newpost = vector<int>(preorder.begin(), preorder.begin()+idx) ;
            //root->left = buildTree(newin, newpost) ; 改2
            root->left = buildTree(newpost, newin) ;
        }   
        if (idx < inorder.size()-1) {
            auto newin = vector<int>(inorder.begin()+idx+1, inorder.end()) ;
            auto newpost = vector<int>(preorder.begin()+idx, preorder.end()) ;
            //root->right = buildTree(newin, newpost) ; 改3
            root->right = buildTree(newpost, newin) ;
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

