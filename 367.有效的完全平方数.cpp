/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, h = num, m ;
        while (l <= h) {
            m = l + (h - l) / 2 ;
            if (num/m==m && num%m==0)  return true ;
            else if (num/m < m)  h = m - 1 ;
            else    l = m + 1 ;
        }
        return false ;
    }

    bool isPerfectSquare1(int num) {
        int l = 1, h = num, m, mm ;
        while (l <= h) {
            m = l + (h - l) / 2 ;
            if (m > 46340) { h = m - 1 ; continue ; }   // 否则int溢出
            mm = m * m ;
            if (mm == num)  return true ;
            else if (mm < num)  l = m + 1 ;
            else h = m - 1 ;
        }
        return false ;
    }
};
// @lc code=end

