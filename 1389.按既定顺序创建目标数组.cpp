/*
 * @lc app=leetcode.cn id=1389 lang=cpp
 *
 * [1389] 按既定顺序创建目标数组
 */

// @lc code=start
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> t ;
        for (int i = 0; i < nums.size(); ++ i)
            t.insert(t.begin()+index[i], nums[i]) ;
        return t ;
    }
};
// @lc code=end

