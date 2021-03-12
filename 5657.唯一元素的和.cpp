/*
 * @lc app=leetcode.cn id=5657 lang=cpp
 *
 * [5657] 唯一元素的和
 */

// @lc code=start
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0, v[101] = { 0 } ;
        for (auto e : nums)  ++ v[e] ; 
        for (int i = 0; i < 101; ++ i)
            sum += (v[i]==1 ? i : 0) ;
        return sum ;
    }
};
// @lc code=end

