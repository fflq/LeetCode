/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 通LC205
    bool wordPattern(string p, string s) {
        unordered_map<char, string> dict ;
        unordered_map<string, char> rdict ;
        vector<string> vec ;

        int idx = 0 ;
        stringstream ss(s) ;
        while (ss >> s) vec.push_back(s) ;

        if (vec.size() != p.size()) return false ;

        for (auto c : p) {
            s = vec[idx++] ;
            if (!dict.count(c)) {
                dict[c] = s ;
                if (!rdict.count(s))   rdict[s] = c ;
                else if (rdict[s] != c)   return false ;
            }
            else if (dict[c] != s)    return false ;
        }
        return true ;
    }
};
// @lc code=end

