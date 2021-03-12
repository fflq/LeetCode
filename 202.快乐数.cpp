/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        set<int> st ;
        while (1) {
            st.insert (n) ;
            n = transform(n) ;
            if (n == 1)  break ;
            if (st.count(n))    return false ;
        }
        return true ;
    }
    int transform(int n) {
        int c, s = 0 ;
        while (n) {
            c = n % 10 ;
            n /= 10 ;
            s += c*c ;
        }
        return s ;
    }
};
// @lc code=end

