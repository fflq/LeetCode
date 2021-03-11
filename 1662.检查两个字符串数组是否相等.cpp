/*
 * @lc app=leetcode.cn id=1662 lang=cpp
 *
 * [1662] 检查两个字符串数组是否相等
 */

// @lc code=start
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "", b = "" ;
        for(auto e : word1)  a += e ;
        for(auto e : word2)  b += e ;
        return a == b ;
    }
};
// @lc code=end

