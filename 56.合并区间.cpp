/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intvs) {
        return merge2(intvs) ;
    }

    // 官方开新vec
    vector<vector<int>> merge2(vector<vector<int>>& intvs) {
        sort (intvs.begin(), intvs.end()) ;

        vector<vector<int>> merged ;
        for (auto e : intvs) {
            if (merged.empty() || merged.back()[1] < e[0])
                merged.push_back (e) ;
            else
                merged.back()[1] = max(merged.back()[1], e[1]) ;
        }
        return merged ;
    }

    // me的超时
    vector<vector<int>> merge1(vector<vector<int>>& intvs) {
        sort (intvs.begin(), intvs.end()) ;

        for (auto it = intvs.begin(); it != intvs.end();) {
            auto nt = it+1 ;
            if (nt != intvs.end() && (*it)[1] >= (*nt)[0]) {
                (*it)[1] = max((*it)[1], (*nt)[1]) ;
                intvs.erase (nt) ;
                continue ;
            }
            ++ it ;
        }
        return intvs ;
    }
};
// @lc code=end

