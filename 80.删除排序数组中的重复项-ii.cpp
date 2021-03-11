/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    // 根据官方题解二写O(n)法
    int removeDuplicates(vector<int>& nums) {
        int num=INT_MIN, numCount=0, n=0 ;
        for (int i = 0; i < nums.size(); ++ i) {
            if (num == nums[i]) numCount ++ ;
            else    (num = nums[i], numCount = 1) ;

            if (numCount <=2)   nums[n++] = nums[i] ;
        }
        return n ;
    }
};
// @lc code=end

