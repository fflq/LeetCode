/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        string keys = "aeiouAEIOU" ;
        for (int i = 0, j = s.size()-1; i < j; ++ i, --j) {
            while (i<j && keys.npos==keys.find(s[i]))  ++ i ;
            while (i<j && keys.npos==keys.find(s[j]))  -- j ;
            swap (s[i], s[j]) ;
        }
        return s ;
    }
};
// @lc code=end

