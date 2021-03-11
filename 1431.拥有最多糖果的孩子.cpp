/*
 * @lc app=leetcode.cn id=1431 lang=cpp
 *
 * [1431] 拥有最多糖果的孩子
 */

// @lc code=start
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxx = INT_MIN ;
        for (auto e : candies)  maxx = max(maxx, e) ;
        vector<bool> res(candies.size(), false) ;
        for (int i = 0; i < candies.size(); ++ i)
            res[i] = (candies[i]+extraCandies >= maxx) ? true : false ; 
        return res ;
    }
};
// @lc code=end

