/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include "heads.h"

// @lc code=start
class Solution {
#ifndef FLQ
#define cout 0&&cout 
#endif
public:
    // 因为固定总大小为m+n，故从后往前
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s = m+n-1, i=m-1, j=n-1 ;
        while (i>=0 && j>=0)
            nums1[s--] = (nums1[i]>nums2[j]) ? nums1[i--] : nums2[j--] ;
        
        j = (i>=0) ? i : j ;
        vector<int> &nums = (i>=0) ? nums1 : nums2 ;
        while (s>=0)    nums1[s--] = nums[j--] ;
    }
};
// @lc code=end

