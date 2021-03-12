/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 官解
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size()-1, m ;
        while (l <= h) {
            m = l + (h - l) / 2 ;
            if (nums[m] < nums[h])  h = m ;
            else if (nums[m] > nums[h]) l = m + 1 ;
            else    -- h ;
        }
        return nums[l] ;
    }

    // wrong，[10,1,10,10,10]
    int findMin1(vector<int>& nums) {
        int l = 0, h = nums.size()-1, m ;
        while (l <= h) {
            m = l + (h - l) / 2 ;
            if (m > 0 && nums[m] < nums[m-1])    return nums[m] ;
            else if (nums[m] >= max(nums[l], nums[h]))   l = m + 1 ;
            else h = m - 1 ;
        }
        return nums.front() ;
    }
};
// @lc code=end

