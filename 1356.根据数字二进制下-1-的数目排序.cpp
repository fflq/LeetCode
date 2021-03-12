/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort (arr.begin(), arr.end(), comp) ;
        return arr ;
    }

    static inline bool comp(int a, int b) {
        int na = getOneNums(a), nb = getOneNums(b) ;
        if (na == nb)   return a < b ;
        else    return na < nb ;
    }

    // 获取数字二进制中1的个数
    static int getOneNums(int a) {
        int c = 0 ;
        while (a) {
            if (a%2)    ++ c ;
            a >>= 1 ;
        }
        return c ;
    }
};
// @lc code=end

