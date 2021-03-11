/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */
#ifdef FLQ
#include <iostream>
#include <cstring>
#include <vector>
using namespace std ;
#endif

// @lc code=start
class Solution {
#ifndef FLQ 
#define cout 0&&cout
#endif
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {            
        vector<vector<int>> vv ;
        int rowNums = A.size() ;
        int colNums = A[0].size() ;
        int rowNumsT = colNums, colNumsT = rowNums ;
        for (int i = 0; i < colNums; ++ i) {
            vector<int> v ;
            for (int j = 0; j < rowNums; ++ j) {                    
                v.push_back(A[j][i]) ;
            }
            vv.push_back(v) ;
        }
        return vv ;
    }
};
// @lc code=end

