/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    // ref
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq_map;
        auto max_freq = 0;
        for (auto n : nums) 
            max_freq = max(max_freq, ++ num_freq_map[n]);

        vector<vector<int>> bucket(max_freq+1);
        for (auto [n, freq] : num_freq_map)
            bucket[freq].push_back(n);

        vector<int> res;
        for (int i = max_freq; i >= 0; -- i) {
            for (auto n : bucket[i]) {
                res.push_back(n);
                if (res.size() == k)    return res;
            }
        }

        return res;
    }
};
// @lc code=end

