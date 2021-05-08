/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 参考题解，dp[i]表示以0~i结尾的最长，故
    // dp[i] = max(dp[j:0~i-1]+1), n[i]>n[j]
    int lengthOfLIS(vector<int>& nums) {
        int dp[2501], maxl = 0 ;

        for (int i = 0; i < nums.size(); ++ i) {
            dp[i] = 1 ;
            for (int j = 0; j < i; ++ j)
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j]+1) ;
            maxl = max(maxl, dp[i]) ;
        }

        return maxl ;
    }
};
// @lc code=end

