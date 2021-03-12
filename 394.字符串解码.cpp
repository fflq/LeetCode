/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 思路，从后往前依次入栈，找到[时出栈找到]，获取中间str，再确定[前的数字n
    // 把str扩展n次，插回栈中，因为可能有嵌套
    // 即，2[a2[bc]] => 2[abcbc] => abcbcabcbc
    // 看题解，两个栈，数字栈，别的栈，更方便
    string decodeString(string s) {
        string ss = "" ;
        stack<char> st ;

        for (int e, n, i = s.size()-1; i >= 0; ) {
            if (s[i] == '[') {
                // 获取需重复串
                string tmp = "" ;
                while (st.top() != ']')  tmp += st.top(), st.pop() ;
                st.pop() ;

                // 获取'['前的数字
                e = -- i ;
                while (i>=0 && isdigit(s[i]))  -- i ;
                n = atoi((s.substr(i+1, e-i)).c_str()) ;

                // 重复n次倒插入stack中
                while (n --) {
                    for (int j = tmp.size()-1; j >= 0; -- j)
                        st.push(tmp[j]) ;
                } 
                
                continue ;
            }

            st.push(s[i--]) ;
        }
        while (!st.empty()) ss += st.top(), st.pop() ;

        return ss ;
    }
};
// @lc code=end

