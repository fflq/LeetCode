/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n = 0 ;
        for (auto c : stones) 
            if (jewels.find_first_of(c) != string::npos)
                ++ n ;
        return n ;
    }
};
// @lc code=end

