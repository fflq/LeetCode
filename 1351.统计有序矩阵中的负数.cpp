/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 *
 * [1351] 统计有序矩阵中的负数
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = 0 ;
        for (auto row : grid)
            for (int i = row.size()-1; i >= 0; -- i)
                if (row[i] < 0)  ++ n ;
                else    break ;
        return n ;
    }
};
// @lc code=end

