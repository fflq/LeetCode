/*
 * @lc app=leetcode.cn id=1309 lang=cpp
 *
 * [1309] 解码字母到整数映射
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 从后往前以#为标志
    string freqAlphabets(string s) {
        string ss = "" ;
        for (int i = s.size()-1; i >= 0; -- i) {
            if (s[i] == '#') {
                i -= 2 ;
                int offs = atoi(s.substr(i, 2).c_str()) ;
                ss += 'j' + offs - 10 ;
            }
            else {
                ss += 'a' + (s[i]-'0') - 1 ;
            }    
        }
        return string(ss.rbegin(), ss.rend()) ;
    }
};
// @lc code=end

