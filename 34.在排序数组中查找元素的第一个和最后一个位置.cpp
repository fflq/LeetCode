/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return searchRange1(nums, target) ;
        return searchRange2(nums, target) ;
        return searchRange3(nums, target) ;
    }

    // 二分模板3，放弃
    vector<int> searchRange3(vector<int>& nums, int t) {
        return {-1, -1} ;
    }

    // 二分模板2，放弃
    vector<int> searchRange2(vector<int>& nums, int t) {
        int l = 0, h = nums.size(), m ;
        while (l < h) {
            m = l + (h - l) / 2 ;
            if (nums[m] < t)    l = m+1 ;
            else    h = m ;
        }
        return {-1, -1} ;
    }

    // 二分模板1
    vector<int> searchRange1(vector<int>& nums, int t) {
        int l = 0, h = nums.size()-1, m ;
        while (l <= h) {
            m = l + (h - l) / 2 ;
            if (nums[m] == t)   break ;
            else if (t < nums[m])   h = m-1 ;
            else    l = m+1 ;
        }

        if (l <= h) {
            l = h = m ;
            while (h+1<nums.size() && nums[h+1]==t)    ++ h ;
            while (l-1>=0 && nums[l-1]==t)    -- l ;
            return {l, h} ;
        }
        else 
            return {-1, -1} ;
    }
};
// @lc code=end

