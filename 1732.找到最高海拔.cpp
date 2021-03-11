/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int m = 0, s = 0 ;
        for (auto e : gain)
            s += e, m = max(m, s) ;
        return m ;
    }
};
// @lc code=end

