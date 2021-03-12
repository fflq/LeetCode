/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int left = 0, up = 0 ;
        for (auto e : moves)
            switch (e)
            {
            case 'U': ++ up ; break;
            case 'D': -- up ; break;
            case 'L': ++ left ; break;
            case 'R': -- left ; break;
            default: break;
            }   
        return !left && !up ;
    }
};
// @lc code=end

