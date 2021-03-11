/*
 * @lc app=leetcode.cn id=1370 lang=cpp
 *
 * [1370] 上升下降字符串
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    const char tag = '*' ;
    string sortString(string s) {
        string res = "" ;
        while (1) {
            char minc=0, maxc=0x7f ;
            int a = 0, b = 0 ;
            while (1) {
                minc = findminc(s, minc) ;
                if (minc)   res += minc ;
                else    break ;
                ++ a ;
            }
            while (1) {
                maxc = findmaxc(s, maxc) ;
                if (maxc)   res += maxc ;
                else    break ;
                ++ b ;
            }
            if (!a && !b)   break ; // 都没有了
        }

        return res ;
    }
    char findminc(string &s, char c) {
        char m = 0x7f ; int mi = -1 ;
        for (int i = 0; i < s.size(); ++ i) 
            if (s[i]!=tag && s[i] > c && s[i] < m)   
                m=s[i], mi=i ;
        if (mi != -1)   s[mi] = tag ;
        return mi==-1 ? 0 : m ;
    }
    char findmaxc(string &s, char c) {
        char m = 0 ; int mi = -1 ;
        for (int i = 0; i < s.size(); ++ i) 
            if (s[i]!=tag && s[i] < c && s[i] > m)   
                m=s[i], mi=i ;
        if (mi != -1)   s[mi] = tag ;
        return mi==-1 ? 0 : m ;
    }

};
// @lc code=end

