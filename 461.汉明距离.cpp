/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    // me用的&，题解有法是亦或z=x^y，然后计算z中1个数即可
    int hammingDistance(int x, int y) {
        long b = 1, c = 0 ;
        while (b <= x || b <= y) {
            c += ((x&b) == (y&b) ? 0 : 1) ; // 注意&优先级
            b <<= 1 ;
        }
        return c ;
    }
};
// @lc code=end

