/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.length()-1; i < j; ++i, --j) {
            while (!isalnum(s[i]) && i<j)  ++ i ;
            while (!isalnum(s[j]) && i<j)  -- j ;
            if (tolower(s[i]) != tolower(s[j])) return false ;
        }
        return true ;
    }
};
// @lc code=end

