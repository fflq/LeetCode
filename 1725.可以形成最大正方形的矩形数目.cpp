/*
 * @lc app=leetcode.cn id=1725 lang=cpp
 *
 * [1725] 可以形成最大正方形的矩形数目
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int c = 0, m, maxx = INT_MIN ;
        vector<int> sq ;
        for (auto e : rectangles) {
            m = min(e[0], e[1]) ;
            maxx = max(maxx, m) ;
            sq.push_back(m) ;
        }
        for (auto e : sq)   if(e == maxx)   ++ c ;
        return c ;
    }
};
// @lc code=end

