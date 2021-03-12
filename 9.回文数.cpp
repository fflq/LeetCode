/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)  return false ;
        long n = 0, m = x ;
        while (m)   n = n*10 + m%10, m /= 10 ;
        return x == n ;
    }

    bool isPalindrome1(int x) {
        if (x < 0)  return false ;
        vector<int> v ;
        while (x)   v.push_back(x%10), x/=10 ;
        for (int i = 0, j = v.size()-1; i < j; ++ i, -- j)
            if (v[i] != v[j])
                return false ;
        return true ;
    }
};
// @lc code=end

