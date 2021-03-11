/*
 * @lc app=leetcode.cn id=1614 lang=cpp
 *
 * [1614] 括号的最大嵌套深度
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int maxDepth(string s) {
        int n = 0, m = 0 ;
        for (auto e : s) {
            if (e == '(')   m = max(m, ++n) ;
            else if (e == ')')  -- n ;
        }
        return m ;
    }
};
// @lc code=end

