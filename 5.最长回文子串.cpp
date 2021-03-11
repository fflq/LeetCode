/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {

    }

    // 暴力超时
    string longestPalindrome1(string s) {
        if (s.size() < 2)   return s ;

        int b = 0, e = 0 ;
        for (int i = 0; i < s.size(); ++ i)
            for (int j = i+1; j < s.size(); ++ j)
                if (isHuiwen (s, i, j) && (j-i)>(e-b))
                    b=i, e=j ;
        cout << b << e << endl ;
        return s.substr(b, e-b+1) ;
    }
    bool isHuiwen(string s, int b, int e) {
        while (b < e)   if (s[b++] != s[e--])   return false ;
        return true ;
    }
};
// @lc code=end

