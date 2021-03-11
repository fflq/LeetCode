/*
 * @lc app=leetcode.cn id=1678 lang=cpp
 *
 * [1678] 设计 Goal 解析器
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    string interpret(string cmd) {
        string s = "" ;
        for (int i = 0; i < cmd.size();) {
            if (cmd[i] == '(') {
                if (cmd[i+1] == ')') {
                    s += 'o' ;
                    i += 2 ;
                }
                else {
                    int e = i+1 ;
                    while (cmd[e] != ')')   ++ e ;
                    s += cmd.substr(i+1, e-i-1) ;
                    i = e + 1 ;
                }
                continue ;
            }
            s += cmd[i] ;
            ++ i ;
        }
        return s ;
    }
};
// @lc code=end

