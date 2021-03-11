/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    // 好好理解指针引用，引用就是当做宏往回带，则
    // node=nullptr => node->left=nullptr
    // node=node->left => node->left=node->left->left 
    TreeNode* deleteNode(TreeNode* &node, int key) {
        if (!node)  return nullptr ;
        if (node->val == key)   delByShape(node) ;
        else if (node->left && key<node->val)    deleteNode(node->left, key) ;
        else if (node->right && key>node->val)    deleteNode(node->right, key) ;
        return node ;
    }
    void delByShape(TreeNode *&node) {
        // node叶子节点，prev还要判断左右
        if (!node->left && !node->right)    node = nullptr ;
        // node单枝节点
        else if (node->left && !node->right)    node = node->left ;
        else if (!node->left && node->right)    node = node->right ;
        // node双节点
        else {
            TreeNode *e = findMax(node->left) ;
            node->val = e->val ;
            deleteNode (node->left, e->val) ;   // 删除替换后的节点
        }    
    }
    TreeNode *findMax(TreeNode *node) {
        while (node->right)   node = node->right ;
        return node ;
    }

    /* 不用引用，用prev，不好写，没写完
    // 加个prev
    TreeNode* delNode(TreeNode *prev, TreeNode* node, int key) {
        if (!node)  return nullptr ;
        cout << "dn" << (prev?prev->val:-1) << node->val << "," << key << endl ;
        if (node->val == key)   delByShap(prev, node) ;
        if (node->left && key<node->val)    delNode(node, node->left, key) ;
        if (node->right && key>node->val)    delNode(node, node->right, key) ;
        return node ;
    }
    // 根据形状删除node
    void delByShap(TreeNode *prev, TreeNode *node) {
        // node叶子节点，prev还要判断左右
        if (!node->left && !node->right)    delByPrev(prev, node, nullptr) ;
        // node单枝节点
        else if (node->left && !node->right)    delByPrev(prev, node, node->left) ;
        else if (!node->left && node->right)    delByPrev(prev, node, node->right) ;
        // node双节点
        else {
            cout << "del" << node->val << endl ;
            TreeNode *e = findMax(node->left) ;
            cout << "find" << e->val << endl ;
            swap(node->val, e->val) ; // 交换node和前驱
            cout << "d" << e->val << endl ;
            delNode (prev, node, e->val) ;
        }    
        //delete node ;
    }
    // 连接prev和next，丢下node
    void delByPrev(TreeNode *prev, TreeNode *node, TreeNode *next) {
        if (prev->left == node) prev->left = next ;
        else    prev->right = next ;
    }
    // 孤立出最大，也就是最右的节点
    TreeNode *popMax(TreeNode *prev, TreeNode *node) {
        if (!node->right) {
            prev->left = node->left ;
            return node ; 
        }
        while (node->right)  prev = node, node = node->right ;
        prev->right =  node->left ;
        return node ;
    }
    */
};
// @lc code=end

