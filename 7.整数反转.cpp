/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long n = abs(x), m = 0 ;

        while (n && n%10 == 0)   n /= 10 ;
        while (n) {
            m = m*10 + (n%10) ;
            n /= 10 ;
        }

        m = x > 0 ? m : -m ;
        return m <= INT_MAX && m >= INT_MIN ? (int)m : 0 ;
    }
};
// @lc code=end

