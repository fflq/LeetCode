/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include "heads.h"

// @lc code=start
class Solution {
#ifndef FLQ
#define cout 0&&cout 
#endif
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1, s ;
        while (i < j) {
            s = nums[i] + nums[j] ;
            if (s > target) -- j ;
            else if (s < target)    ++ i ;
            else    break ;
        }
        // result index from 1
        return {i+1, j+1} ;
    }
};
// @lc code=end

