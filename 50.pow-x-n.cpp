/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1 ;

        double t = myPow(x, n/2) ;
        if (n % 2 == 0) return t*t ;
        else    return n > 0 ? x*t*t : t*t/x ;  // 2^-2
    }
};
// @lc code=end

