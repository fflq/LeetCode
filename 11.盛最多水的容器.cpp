/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size()-1, s = 0 ;
        while (i < j) {
            s = max(s, (j-i)*min(heights[i], heights[j])) ;
            heights[i] < heights[j] ? ++ i : -- j ;
        }
        return s ;
    }
};
// @lc code=end

