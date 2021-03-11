/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxx = INT_MIN ;
        for (auto e : accounts)
            maxx = max(maxx, sum(e)) ;
        return maxx ;
    }
    int sum(vector<int> &e) {
        int s = 0 ;
        for (auto a : e)    s += a ;
        return s ;
    }
};
// @lc code=end

