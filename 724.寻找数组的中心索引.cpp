/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 官方题解，sum = 2*left + nums[i]
    int pivotIndex(vector<int>& nums) {
        int i = 0, left = 0, sum = accumulate(nums.begin(), nums.end(), 0) ;
        for (i = 0; i < nums.size(); ++ i) {
            if (sum == 2*left + nums[i])    return i ;
            left += nums[i] ;
        }
        return -1 ;
    }

    // 想双指针一遍过，结果发现两边移动，在负数情况下有问题
    // 失败
    int pivotIndex1(vector<int>& nums) {
        if (nums.empty())   return -1 ;

        int i = 0, j = nums.size()-1, si = 0, sj = 0 ;
        int sum = accumulate(nums.begin(), nums.end(), 0), sign = 1 ;
        sum = (sum>0 ? sum : (sign=-1, -sum)) / 2 ;

        // 尽可能靠左
        for (i = 0; i < nums.size(); ++ i) {
            si += sign*nums[i] ;
            if (si > sum)  break ; 
            //if (si == sum && nums[i] == 0) break ;
        }
        // 尽可能靠右
        for (j = nums.size()-1; j >= 0; -- j) {
            sj += sign*nums[j] ;
            if (sj > sum)  break ;
        }

        if (si != sj)   return -1 ;
        else {
            if (i == j) return i ;
            else if (i == j+1)  return -1 ;
            else if (j < i)    return j+1 ;
            else return i ;
        }
    }
};
// @lc code=end

