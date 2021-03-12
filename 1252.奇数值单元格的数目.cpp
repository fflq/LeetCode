/*
 * @lc app=leetcode.cn id=1252 lang=cpp
 *
 * [1252] 奇数值单元格的数目
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    #define isOdd(a) ((a)%2==1)
    typedef vector<vector<int>> vvi_t ;
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        //vvi_t v = vvi_t(n, vector<int>(m, 0)) ;

        // 先统计好所有行列要加的数
        int drow[n], dcol[m] ;
        memset(drow, 0, sizeof(drow)) ;
        memset(dcol, 0, sizeof(dcol)) ;
        for (auto row : indices)    ++ drow[row[0]], ++ dcol[row[1]] ;

        // 直接考虑行列所加值奇偶，而不是修改到实际矩阵中
        int c = 0 ;
        for (int i = 0; i < n; ++ i) {
            if (isOdd(drow[i]))  c += m ;   // 整行都是奇数
            for (int j = 0; j < m; ++ j) {
                if (!dcol[j])   continue ;
                if (isOdd(drow[i]) && isOdd(dcol[j]))    -- c ; // 奇加奇为偶
                if (!isOdd(drow[i]) && isOdd(dcol[j]))    ++ c ; // 偶加奇为奇
            }
        }

        return c ;
    }
};
// @lc code=end

