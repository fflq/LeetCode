/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int tgt, n = 0 ;
        map<int, int> mp ;
        for (auto a : A) for (auto b : B) { mp[-a-b] ++ ; }
        for (auto c : C) for (auto d : D)   n += mp[c+d] ;
        return n ;
    }

    // 暴力超时
    int fourSumCount1(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int l, h, m, tgt, n = 0 ;
        sort (D.begin(), D.end()) ;
        for (auto a : A) for (auto b : B) for (auto c : C) {
            tgt = - (a + b + c) ;
            l = 0, h = D.size()-1 ;
            while (l <= h) {
                m = l + (h - l) / 2 ;
                if (D[m] == tgt) {
                    ++ n ;
                    l = h = m ; 
                    while (l > 0 && D[--l] == tgt)   ++ n ;
                    while (h < D.size()-1 && D[++h] == tgt)   ++ n ;
                    break ;
                }
                else if (D[m] < tgt)    l = m + 1 ;
                else    h = m - 1 ;
            }
        }
        return n ;
    }
};
// @lc code=end

