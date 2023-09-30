/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        nums.insert(nums.begin(), {0,0});
        vector<int> dps(110,-1);
        return robLoop(nums, dps);
        int s = robRecursion(nums, 0, nums.size(), dps);
        //print_vec(dps);
        return s;
    }

    //dp[i] = max(dp[i-1], d[i-2]+nums[i])
    //dp[0] = nums[0]; dp[1] = max(nums[0],nums[1])
    int robLoop(vector<int>& nums, vector<int>& dps) {
        if (nums.empty())   return 0;
        dps[0] = nums[0];
        dps[1] = max(nums[0], nums[1]);
        for (auto i = 2; i < nums.size(); ++ i)
            dps[i] = max(dps[i-1], dps[i-2]+nums[i]);
        return dps[nums.size()-1];
    }

    int robRecursion(vector<int>& nums, int beg, int end, vector<int>& dps) {
        if (beg == end) return 0;
        if (end - beg <= 2) return nums[beg];

        int max_sum = nums[beg];
        //this time gap n house will steal max
        for (int i = beg+2; i < end; ++ i) {
            if (dps[i] < 0)
                dps[i] = robRecursion(nums, i, end, dps);
            max_sum = max(max_sum, nums[beg] + dps[i]); 
        }
        dps[beg] = max_sum;
        return max_sum;
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        vector<int> s{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        assert(sol.rob(s) == 0);
    }
    {
        vector<int> s{1,2,1,1};
        assert(sol.rob(s) == 3);
    }
    {
        vector<int> s{1,2,3,1};
        assert(sol.rob(s) == 4);
    }
    {
        vector<int> s{2,7,9,3,1};
        assert(sol.rob(s) == 12);
    }
    return 0;
}