/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 比较排序前后变动的个数
    int heightChecker(vector<int>& heights) {
        vector<int> v = vector<int>(heights.begin(), heights.end()) ;
        sort (v.begin(), v.end()) ;
        int n = 0 ;
        for (int i = 0; i < v.size(); ++ i)
            if (v[i] != heights[i])
                ++ n ;
        return n ;
    }
};
// @lc code=end

