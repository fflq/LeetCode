/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort (nums.begin(), nums.end()) ;
        int s = 0 ;
        for (int i = 0; i < nums.size(); i += 2)    s += nums[i] ;
        return s ;
    }
};
// @lc code=end

