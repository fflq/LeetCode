/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxn = 0, n = 0 ;
        for (int i = 0, f = 0; i < nums.size(); ++ i) {
            if (nums[i] == 1)   f = 1, ++ n ;
            else if (f == 1) {
                maxn = max(n, maxn) ;
                f = n = 0 ;
            }
        }
        maxn = max(n, maxn) ;
        return maxn ;
    }
};
// @lc code=end

