/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        uint64_t left = 0, right = sqrt(c) ;
        while (left <= right) {
            uint64_t sum = left*left + right*right ;
            if (sum == c)   return true ;
            else if (sum < c)   ++ left ;
            else    -- right ;
        }
        return false;
    }
};
// @lc code=end

