/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    string toLowerCase(string str) {
        for (auto &c : str)
            c = tolower(c) ;
        return str ;
    }
};
// @lc code=end

