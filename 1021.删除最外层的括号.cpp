/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 就是去掉一层括号而已
    string removeOuterParentheses(string S) {
        int n = 0 ;
        string ss = "" ;
        for (auto c : S) {  // ++和--前后位置
            if (c == '(') { // 不可合并
                if (n++ > 0)    ss += c ; 
            }
            else if (--n > 0)  ss += c ;
        }
        return ss ;
    }
};
// @lc code=end

