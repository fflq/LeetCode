/*
 * @lc app=leetcode.cn id=1704 lang=cpp
 *
 * [1704] 判断字符串的两半是否相似
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    bool halvesAreAlike(string s) {
        int ac = 0, bc = 0 ;
        string cs = "aeiouAEIOU" ;
        for (int i = 0; i < s.size(); ++ i)
            if (cs.find_first_of(s[i]) != string::npos)
                (i < s.size()/2) ? ++ac : ++ bc ;
        return ac == bc ;
    }
};
// @lc code=end

