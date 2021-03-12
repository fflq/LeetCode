/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0, b = 0, f = 0; i < s.size(); ++ i) {
            if (f == 0 && !isblank(s[i]) )   f = 1, b = i ;
            // 最后一个要额外注意
            else if (f == 1 && (i == s.size()-1 || isblank(s[i])) )   f = 0, turn(s, b, isblank(s[i]) ? i-1 : i) ;
        }
        return s ;
    }

    void turn(string &s, int b, int e) { while (b < e)   swap(s[b++], s[e--]) ; }
};
// @lc code=end

