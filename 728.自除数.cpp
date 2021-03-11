/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v ;
        for (int i = left; i <= right; ++ i)    if (isNa(i))    v.push_back(i) ;
        return v ;
    }

    bool isNa(int a) {
        int n = a, m ;
        while (n) {
            m = n % 10 ;
            if (!m)  return false ;
            else if (a % m)  return false ;
            n /= 10 ;
        }
        return true ;
    }
};
// @lc code=end

