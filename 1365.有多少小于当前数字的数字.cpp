/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res ;
        for (int i = 0; i < nums.size(); ++ i) {
            int c = 0 ;
            for (auto e : nums) if (e < nums[i]) ++ c ;
            res.push_back (c) ;
        }
        return res ;
    }
};
// @lc code=end

