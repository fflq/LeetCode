/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    // 1 2 3 = 1 2 3, 3 2 1 = 3 2 1, 1 3 2 = 1 2 1
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++ i) {
            if (ratings[i] > ratings[i-1])
                candies[i] = max(candies[i], candies[i-1] + 1);
        }
        for (int i = ratings.size()-2; i >= 0; -- i) {
            if (ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], candies[i+1] + 1);
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        vector<int> s{1,3,4,5,2};
        assert(sol.candy(s));
    }
    return 0 ;
}