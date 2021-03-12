/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for (int i = 1, j = n; i < 2*n; i += 2, ++ j) {
            int s = nums[j] ;
            nums.erase (nums.begin()+j) ;
            nums.insert (nums.begin()+i, s) ;
        }
        return nums ;
    }
};
// @lc code=end

