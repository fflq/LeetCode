/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child_ate_cnt = 0;
        for (int i = 0, j = 0; i < g.size() && j < s.size();) {
            if (g[i] <= s[j]) {
                ++ child_ate_cnt;
                ++ i;
            }
            ++ j;
        }
        return child_ate_cnt;
    }
};
// @lc code=end

