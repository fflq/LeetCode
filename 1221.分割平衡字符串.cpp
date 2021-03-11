/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
class Solution {
public:
    int balancedStringSplit(string s) {
        int lc = 0, rc = 0, c = 0 ;
        for (int i = 0; i < s.size(); ++ i) {
            (s[i] == 'L') ? ++ lc : ++ rc ;
            if (lc == rc)   ++ c ;
        }
        return c ;
    }
};
// @lc code=end

