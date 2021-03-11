/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        // ')' == '('+1，但是另两个居然是+2
        vector<char> vec = { '(', '[', '{' } ;  
        stack<char> st ;
        for (auto c : s) {
            //if (find(vec.begin(), vec.end(), c) != vec.end())   st.push(c) ;
            if (c==vec[0] || c==vec[1] || c==vec[2])   st.push(c) ;
            else if (st.empty() || (c-1 != st.top() && c-2 != st.top()))    return false ; 
            else    st.pop () ;
        }
        return st.empty() ? true : false ;
    }
};
// @lc code=end

