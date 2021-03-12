/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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

class Codec {
public:
    const string delim = "," ;
    const string nullstr = "#" ;

    // Encodes a tree to a single string.
    // [1,2,3,null,null,4,5] => 123##45####
    string serialize(TreeNode* root) {
        if (!root)  return "" ;
        queue<TreeNode *> que ;
        que.push (root) ;        
        string s = "" ;
        while (!que.empty()) {
            TreeNode *p = que.front(); que.pop() ;
            s += p ? to_string(p->val) : nullstr ;
            s += delim ;
            if (p)  que.push(p->left), que.push(p->right) ;
        }
        return s ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())   return nullptr ;

        int idx = 0 ;
        auto vec = splitStr(data, delim) ;
        auto root = new TreeNode(atoi(vec[idx++].c_str())) ;
        queue<TreeNode *> que ;
        que.push (root) ;

        while (!que.empty() && idx < vec.size()) {
            TreeNode *p = que.front(); que.pop() ;

            string s = vec[idx++] ;
            if (s != nullstr) {
                p->left = new TreeNode(atoi(s.c_str())) ;
                que.push (p->left) ;
            }
            s = vec[idx++] ;
            if (s != nullstr) {
                p->right = new TreeNode(atoi(s.c_str())) ;
                que.push (p->right) ;
            }
        }
        return root ;
    }

    vector<string> splitStr(string s, string delim) {
        vector<string> v ;
        string::size_type beg, pos = 0 ;
        while (pos != s.npos) {
            beg = s.find_first_not_of(delim, pos) ;
            if (beg == s.npos)  break ;
            pos = s.find_first_of(delim, beg) ;
            v.push_back (s.substr(beg, pos-beg)) ;
        }
        return v ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

