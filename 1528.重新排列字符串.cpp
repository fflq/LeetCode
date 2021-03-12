/*
 * @lc app=leetcode.cn id=1528 lang=cpp
 *
 * [1528] 重新排列字符串
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // me想到的一法是双for按序swap，一法是单for直接swap(错)，一法是开新string
    string restoreString(string s, vector<int>& indices) {
        return restoreString1(s, indices) ;
    }

    // 依次寻找0-n位置的元素，swap到正确位置
    string restoreString1(string &s, vector<int>& indices) {
        for (int i = 0; i < s.size(); ++ i) 
            for (int j = i; j < s.size(); ++ j) {
                if (indices[j] == i) {
                    swap (s[i], s[j]) ;
                    swap (indices[i], indices[j]) ;
                    break ;
                }
            }
        return s ;
    }

    // 单for直接swap，错
    string restoreString2(string &s, vector<int>& indices) {
        for (int i = 0; i < s.size(); ++ i)
            if (i != indices[i])
                swap(s[i], s[indices[i]]), swap(indices[i], indices[indices[i]]) ;
        return s ;
    }

    // 新string
    string restoreString3(string &s, vector<int>& indices) {
        string ns = string(s.size(), 0) ;
        for (int i = 0; i < s.size(); ++ i)
            ns[indices[i]] = s[i] ;
        return ns ;
    }
};
// @lc code=end

