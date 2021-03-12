/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    // O(nlogn)的前缀和+二分查找
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, k, t, minLen = INT_MAX ;

        // snums[i] = nums[0+...i-1]
        auto snums = vector<int>(nums.size()+1, 0) ;
        for (i = 1; i <= nums.size(); ++ i)  snums[i] = snums[i-1] + nums[i-1] ;

        for (i = 0; i < nums.size(); ++ i) {
            t = s + snums[i] ;
            auto bound = lower_bound (snums.begin(), snums.end(), t) ;
            if (bound != snums.end()) {
                // bound.pos - i => i...k, which is fit
                k = (bound - snums.begin()) - i ;
                minLen = min(minLen, k) ;
            }
            //cout << i << " " << k << " " << minLen << endl ;
        }
        minLen = minLen==INT_MAX ? 0 : minLen ;   // no exist
        return minLen ;
    }
    /* O(n)的滑动窗口
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0 ;
        int len = 1, minLen = INT_MAX, sum = nums.empty() ? 0 : nums[0] ;
        while (i <= j && j < nums.size()) {
            if (sum >= s)   sum-=nums[i++], minLen=min(minLen, len--) ;
            else    ++j<nums.size() ? sum+=nums[j], len++: 0 ;
            // avoid j over limit
        }
        minLen = minLen==INT_MAX ? 0 : minLen ;   // no exist
        return minLen ;
    }
    */
};
// @lc code=end

