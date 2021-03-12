/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start
class Solution {
public:
    // 原地操作，有点绕
    vector<int> decode(vector<int>& encoded, int first) {
        encoded.insert (encoded.begin(), first) ;   
        for (int i = 1; i < encoded.size(); ++ i)
            encoded[i] = encoded[i-1] ^ encoded[i] ;
        return encoded ;
    }
};
// @lc code=end

