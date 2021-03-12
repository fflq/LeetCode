/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        return reverseWords1(s) ;
    }


    // 暴力
    string reverseWords1(string s) {
        string ss = "" ;
        for (int i = s.size()-1, n = 0, b, e; i >= 0; -- i) {
            if (n == 0 && !isblank(s[i]))   b = e = i, ++ n ;
            else if (n == 1 && (isblank(s[i]) || i == 0)) {
                b = isblank(s[i]) ? i+1 : i ;   // 第一位是否为空格

                ss += s.substr(b, e-b+1) + " " ;

                n = 0 ; b = e = -1 ;
            }
            if (i == 0 && e != -1)  ss += s.substr(b, e-b+1) + " " ;
        }
        return ss.substr(0, ss.size()-1) ;
    }
};
// @lc code=end

