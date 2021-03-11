/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int i, c = 0 ;
        for (auto e : words) {
            for (i = 0; i < e.size(); ++ i)
                if (allowed.find_first_of(e[i]) == string::npos)
                    break ;
            if (i == e.size())  ++ c ;
        }
        return c ;
    }
};
// @lc code=end

