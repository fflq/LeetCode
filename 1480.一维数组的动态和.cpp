/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sums(nums.size(), 0) ;
        sums[0] = nums[0] ;
        for (int i = 1; i < nums.size(); ++ i)
            sums[i] = sums[i-1] + nums[i] ;         
        return sums ;
    }
};
// @lc code=end

