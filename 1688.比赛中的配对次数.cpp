/*
 * @lc app=leetcode.cn id=1688 lang=cpp
 *
 * [1688] 比赛中的配对次数
 */

// @lc code=start
class Solution {
public:
    int numberOfMatches(int n) {
        int c = 0 ;
        while (n != 1) {
            c += n/2 ; 
            n = (n/2 + (n%2?1:0) ) ;
        }
        return c ;
    }
};
// @lc code=end

