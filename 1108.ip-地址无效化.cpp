/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
        string s = "" ;
        for (auto c : address) {
            if ('.' == c)   s += "[.]" ;
            else    s += c ;
        }
        return s ;
    }
};
// @lc code=end

