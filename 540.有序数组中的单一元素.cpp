/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    //思路: 因为要logn, 那么应该是要二分查找
    //1. 原本想着就是递归二分然后比较前后
    //2. 但是看到了提示, 不用递归两边, 可以根据奇偶选边 
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (m % 2 == 0) {
                if (nums[m] == nums[m+1])   l = m + 2;
                else    r = m;
            }
            else {
                if (nums[m] == nums[m-1])   l = m + 1;
                else    r = m - 1;
            }
        }
        return nums[l];
    }
};
// @lc code=end

