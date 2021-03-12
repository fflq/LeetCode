/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 即终点站不作为path开头
    string destCity(vector<vector<string>>& paths) {
        set<string> heads, ends ;
        for (auto vs : paths) {
            heads.insert (vs.front()) ;
            ends.insert (vs.back()) ;
        }
        for (auto s : ends)
            if (!heads.count(s))
                return s ;
        return "" ;
    }
};
// @lc code=end

