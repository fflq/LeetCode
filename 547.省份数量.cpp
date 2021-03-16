/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int *ufsInit(int n) { 
        int *fa = new int[n] ;
        for (int i = 0; i < n; ++ i)    fa[i] = i ; 
        return fa ;
    }
    void ufsDeinit(int *fa) { delete fa ; }
    int ufsFather(int *fa, int e) {
        int x = e, y = e, z ;
        while (x != fa[x])  x = fa[x] ;
        while (y != fa[y])  z = y, y = fa[y], fa[z] = x ;
        return x ;
    }
    int ufsUnion(int *fa, int a, int b) {
        a = ufsFather(fa, a), b = ufsFather(fa, b) ;
        if (a != b) fa[b] = a ;
        return a ;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int *fa = ufsInit(isConnected.size()+1) ;
        set<int> st ;
        for (int i = 0; i < isConnected.size(); ++ i)
            for (int j = 0; j < isConnected[0].size(); ++ j)
                if (isConnected[i][j])   ufsUnion(fa, i, j) ;
        for (int i = 0; i < isConnected.size(); ++ i)
            st.insert (ufsFather(fa, i)) ;
        return st.size() ;
    }
};
// @lc code=end

