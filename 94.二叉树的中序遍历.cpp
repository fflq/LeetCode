/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> vec ;
    vector<int> inorderTraversal(TreeNode* root) {
        //inorder(root) ;
        //inorder2(root) ;
        inorder3(root) ;
        return vec ; 
    }

    // 非递归，官方无set版本
    void inorder3(TreeNode *root) {
        stack<TreeNode *> st ;
        while (root || !st.empty()) {
            while (root)  st.push(root), root = root->left ;

            TreeNode *mid = st.top() ; st.pop() ;
            vec.push_back (mid->val) ;
            root = mid->right ; // 切换了线路，就不会有while(root)重复添加了，故无需set
        }
    }

    // 非递归(画出遍历时栈的变化，再写就容易多了)
    void inorder2(TreeNode *root) {
        stack<TreeNode *> st ;
        set<TreeNode *> vist ;
        if (root)   st.push(root) ;

        while (!st.empty()) {
            TreeNode *p = st.top() ;

            if (p->left && !vist.count(p->left)) {  // 有未访问的左节点时，则依次到底入栈
                while (p->left) { st.push(p->left) ; p = p->left ; }
            }
            else {  // 无左节点时，则输出当前，并添加右节点
                st.pop() ;
                vist.insert(p) ;
                vec.push_back(p->val) ; //cout << p->val << endl ;
                if (p->right)   st.push(p->right) ;
            }
        }
    }

    void inorder(TreeNode *root) {
        if (root) {
            inorder (root->left) ;
            vec.push_back (root->val) ;
            inorder (root->right) ;
        }
    }
};
// @lc code=end

