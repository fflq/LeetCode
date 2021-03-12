/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long l = 1, r = n, m ;
        while (l <= r) {
            m = (l + r) / 2 ;
            if (guess(m) == 0)  return m ;
            else if (guess(m) > 0)  l = m + 1 ;
            else    r = m - 1 ;
        }
        return -1 ;
    }
};
// @lc code=end

