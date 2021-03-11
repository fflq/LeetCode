/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class KthLargest {
public:
    // 按要求写二叉搜索树解法(堆写法，k快排以前写过)
    KthLargest(int k, vector<int>& nums): theK(k), root(nullptr) {
        for (auto e : nums)  insertSTree(root, e) ;
    }

    int add(int val) {
        insertSTree (root, val) ;
        return findK(root, theK) ;
    }

private :
    typedef struct stree{
        int val, cnt ;  // cnt为以此为根的树总结点数
        struct stree *lchild, *rchild ;
        stree(int v, int c): val(v), cnt(c), lchild(nullptr), rchild(nullptr) {}
    } STree, *PSTree ;
    int theK ;
    PSTree root ;

    // 构建二叉搜索树
    void insertSTree(PSTree &root, int e) {
        if (!root)  root = new STree(e, 1) ;
        else {
            if (e < root->val)  insertSTree(root->lchild, e) ;
            else    insertSTree(root->rchild, e) ;
            ++ root->cnt ;
        }
    }
    
    int findK(PSTree root, int k) {
        if (!root)  return -1 ;

        int rcnt = root->rchild ? root->rchild->cnt : 0 ; // 右子树节点数
        if (rcnt >= k)  return findK(root->rchild, k) ; // 在右边
        else if (rcnt == k-1)   return root->val ; // 就是root
        else    return findK(root->lchild, k-rcnt-1) ; // 在左边
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

