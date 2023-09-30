/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    //ref 
    int deleteAndEarn(vector<int>& nums) {
        vector<int> rob_nums(10010, 0);
        for (auto n : nums)
            rob_nums[n] += n;
        return rob(rob_nums);
    }

    int rob(vector<int>& nums) {
        if (nums.empty())   return 0;
        vector<int> dps(nums.size()+10, 0);
        dps[0] = nums[0];
        dps[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++ i) 
            dps[i] = max(dps[i-1], dps[i-2]+nums[i]);
        return dps[nums.size()-1];
    }

    //TLE
    /*
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dps(20010, -1);
        multiset<int> rm_mset;
        rm_mset.insert(0);
        return deleteAndEarnRecursion(nums, dps, rm_mset);
    }

    int deleteAndEarnRecursion(vector<int>& nums,
        vector<int>& dps, multiset<int>& rm_mset) {
        if (nums.empty())   return 0;
        int max_sum = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            if (rm_mset.count(nums[i]))   continue;

            int num = nums[i];
            nums[i] = 0;
            rm_mset.insert(num-1);
            rm_mset.insert(num+1);
            max_sum = max(max_sum,
                num+deleteAndEarnRecursion(nums, dps, rm_mset));
            rm_mset.extract(num-1);
            rm_mset.extract(num+1);
            nums[i] = num;
        }
        return max_sum;
    }
    */
};
// @lc code=end

int main() {
    Solution sol;
    {
        vector<int> s{8,3,4,7,6,6,9,2,5,8,2,
            4,9,5,9,1,5,7,1,4};
        assert(sol.deleteAndEarn(s) == 61);
    }
    {
        vector<int> s{2,2,3,3,3,4};
        assert(sol.deleteAndEarn(s) == 9);
    }
    {
        vector<int> s{3,4,2};
        assert(sol.deleteAndEarn(s) == 6);
    }
    return 0;
}