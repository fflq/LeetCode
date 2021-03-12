/*
 * @lc app=leetcode.cn id=1374 lang=cpp
 *
 * [1374] 生成每种字符都是奇数个的字符串
 */

// @lc code=start
class Solution {
public:
    // 偶=奇+奇，奇=(奇+奇)+奇
    string generateTheString(int n) {
        string s = "" ;
        if (n%2) { // 奇
            s += 'z' ;
            if (n > 1)  s += generateTheString(n-1) ;
        }
        else {
            s += string(1, 'a') ;
            if (n > 1)  s += string(n-1, 'b') ;
        }
        return s ;
    }
};
// @lc code=end

