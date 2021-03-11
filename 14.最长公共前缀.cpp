/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())   return "" ;

        string s = strs[0] ;
        int len = INT_MAX ;
        for (int i = 1, j; i < strs.size(); ++ i) {
            for (j = 0; j < min(s.size(), strs[i].size()); ++ j) {
                if (s[j] != strs[i][j]) break ;
            }
            len = min(len, j) ;
            if (0 == len)   return "" ; // 提前结束
        }

        return len == INT_MAX ? s : s.substr(0, len) ;
    }

    // 错，此法得到["flower","flow","flight"]前缀flow
    string longestCommonPrefix1(vector<string>& strs) {
        if (strs.empty())   return "" ;
        if (strs.size() == 1)   return strs[0] ;

        // 按长度排序，而非字典序
        sort (strs.begin(), strs.end(), comp) ;

        // 因为是公共前缀，若存在，则前两必有，找出
        string a = strs[0], b = strs[1] ; int len = 0 ;
        for (int i = 0; i < min(a.size(), b.size()); ++ i)
            if (a[i] == b[i])   ++len ;
            else    break ;
        if (len == 0)   return "" ;
        string s = a.substr(0, len) ;
        cout << s << endl ;

        // 前两的前缀，是否后续元素都满足
        for (int i = 2; i < strs.size(); ++ i) {
            if (strs[i].size() < len)   return "" ;
            //cout << strs[i].substr(0, len) << endl ;
            if (strs[i].substr(0, len) != s)    return "" ;  
        }

        return s ;
    }
    static bool comp(string &a, string &b) {return a.size()<b.size() ; }
};
// @lc code=end

