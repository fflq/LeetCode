/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        return strStr2(haystack, needle) ;
    }

    // 暴力
    int strStr2(string s, string p) {
        int si, j ;
        for (si = 0; si <= (int)(s.size()-p.size()); ++ si) {
            for (j = 0; j < p.size(); ++ j)
                if (s[si+j] != p[j])   break ;
            if (j == p.size())    return si ;
        }
        return p.empty() ? 0 : -1 ;
    }

    // 调函数
    int strStr1(string haystack, string needle) {
        const char *s = strstr(haystack.c_str(), needle.c_str()) ;
        return s ? s-haystack.c_str() : -1 ;
    }
};
// @lc code=end

