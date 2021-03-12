/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st ;
        for (auto s : tokens) {
            if (!isdigit(s[0]) && s.size()==1) { // 避免数字-123误认为-
                int a = st.top() ; st.pop() ;
                int b = st.top(), c ; st.pop() ;
                switch(s[0]) {
                    case '+': c = b + a ; break ;
                    case '-': c = b - a ; break ;
                    case '*': c = b * a ; break ;
                    case '/': c = b / a ; break ;
                }
                st.push (c) ;
            }
            else    st.push(atoi(s.c_str())) ;
        }
        return st.top() ;
    }
};
// @lc code=end

