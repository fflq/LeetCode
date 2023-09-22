/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    //brute force, TLE
    /*
    int maxProfit(vector<int>& prices) {
        auto sz = prices.size();
        int max_profit = 0;
        for(int i = 0; i < sz; ++ i) {
            int buy_price = prices[i];
            for(int j = i+1; j < sz; ++ j) {
                int sale_price = prices[j];
                max_profit = max(sale_price-buy_price, max_profit);
            }
        }
        return max_profit;
    }
    */
    int maxProfit(vector<int>& prices) {
        //table
        vector<int> right_max_prices(prices.size());
        right_max_prices[prices.size()-1] = prices[prices.size()-1];
        for (int i = prices.size()-2; i >= 0; -- i) {
            right_max_prices[i] = max(right_max_prices[i+1], prices[i]);
        }

        //find
        int max_profit = 0;
        for (int i = 0; i < prices.size(); ++ i) {
            max_profit = max(max_profit, right_max_prices[i]-prices[i]);
        }

        return max_profit;
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
    auto s = vector<int>{7,1,5,3,6,4};
    assert(sol.maxProfit(s) == 5);
    }
    {
    auto s = vector<int>{7,6,4,3,1};
    assert(sol.maxProfit(s) == 0);
    }
    return 0;
}