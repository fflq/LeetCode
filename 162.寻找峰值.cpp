/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    // 暴力略过，官解二分模板2，峰值总是在mid升的那边
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1, m ;
        while (l < r) {
            m = l + (r - l)/2 ;
            if (nums[m] > nums[m+1])    r = m ;
            else    l = m + 1 ; // 若l=m,r=m-1则出错 
        }
        return l ;
    }
};
// @lc code=end

