/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 仿照LC15三数之和
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res ;
        sort (nums.begin(), nums.end()) ;
        for (int i = 0, n = nums.size(); i < n; ++ i) {
            if (i > 0 && nums[i] == nums[i-1])  continue ;

            for (int j = i+1; j < n; ++ j) {
                if (j > i+1 && nums[j] == nums[j-1])  continue ;

                int p = n-1, tgt=target-nums[i]-nums[j] ;
                for (int k = j+1; k < n; ++ k) {
                    if (k > j+1 && nums[k] == nums[k-1])    continue ;

                    while (p > k && nums[k]+nums[p]>tgt)    -- p ;

                    if (p == k)  break ;

                    if (nums[k] + nums[p] == tgt)   
                        res.push_back({nums[i], nums[j], nums[k], nums[p]}) ;
                }
            }
        }
        return res ;
    }
};
// @lc code=end

