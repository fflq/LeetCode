/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    typedef vector<vector<int>> vv_t ;
    vv_t tbs = { {1} } ; // 若放在func内做static会出错，即使是第一次执行，也可能是size==5
    vector<vector<int>> generate(int numRows) {
        return updateYHT(numRows) ;
    }

    vv_t updateYHT(int num) {
        if (tbs.size() > num)   return vv_t(tbs.begin(), tbs.begin()+num) ;   // 打表

        for (int i = tbs.size(); i < num; ++ i) {   // 只添加表里没有的
            vector<int> v = {1} ;
            for (int j = 1; j < i; ++ j)    v.push_back (tbs[i-1][j-1] + tbs[i-1][j]) ;
            v.push_back (1) ;
            tbs.push_back (v) ;
        }

        return tbs ;
    }
};
// @lc code=end

