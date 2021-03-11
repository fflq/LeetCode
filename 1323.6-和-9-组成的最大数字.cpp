/*
 * @lc app=leetcode.cn id=1323 lang=cpp
 *
 * [1323] 6 和 9 组成的最大数字
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num) ;
        for (auto &c : s)   
            if (c == '6') {
                c = '9' ;
                break ;
            }
        return stoi(s) ;
    }

    int maximum69Number1 (int num) {
        char buf[5] = { '\0' } ;
        sprintf (buf, "%d", num) ;
        int len = strlen(buf) ;
        for (int i = 0; i < len; ++ i)
            if (buf[i] == '6') {
                buf[i] = '9' ;
                break ;
            }
        return atoi(buf) ;
    }
};
// @lc code=end

