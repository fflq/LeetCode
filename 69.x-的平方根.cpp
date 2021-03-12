/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    // 二分写法
    int mySqrt(int x) {
        long left = 1, right = x, mid, m, n ;
        while (left <= right) {
            mid = (left + right) / 2 ;
            m = mid * mid ;
            n = (mid+1) * (mid+1) ;
            if (x >= m && x < n)    return mid ;
            else if (x < m) right = mid-1 ;
            else if (x > m) left = mid+1 ;
        }
        return 0 ;
    }
};
// @lc code=end

