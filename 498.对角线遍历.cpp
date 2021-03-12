/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        return findDiagonalOrder2(matrix) ;
    }

    // 官方，简化列出所有对角线，再处理倒转
    vector<int> findDiagonalOrder2(vector<vector<int>>& matrix) {
        if (matrix.empty())   return {} ;
        
        int i = 0, j = 0, k = 0, m = matrix.size(), n = matrix[0].size() ;
        vector<int> temp, res ;

        // m*n有m+n-1个对角线，并根据k得出行列号ij
        for (k = 0; k < m+n-1; ++ k) {
            //i = k < m ? k%m : m-1 ;
            i = k < m ? k : m-1 ;
            j = k < m ? 0 : k-i ;

            temp.clear () ;
            while (isOk(i, j, m, n)) {
                //cout << matrix[i][j] << ", " ;
                temp.push_back (matrix[i][j]) ;
                -- i, ++ j ;
            }
            // (i+j)%2是错的
            if (k % 2 == 0)   res.insert (res.end(), temp.begin(), temp.end()) ;
            else    res.insert (res.end(), temp.rbegin(), temp.rend()) ;
        }
        return res ;
    }
    bool isOk(int i, int j, int m, int n) {
        return (i<m && i>=0 && j<n && j>=0) ;
    }

    // 模拟路径，费时没写出
    // 有个toggle决定往上还是下
    // 往上时，row+=-1， col+=1；往下时，row+=1，col+=-1 
    // 即row+=dir, col+=dir，超过边界则结束一次循环并重置
    vector<int> findDiagonalOrder1(vector<vector<int>>& matrix) {
        if (matrix.empty())   return {} ;

        const int UP=-1, DOWN=1 ;
        int dir = UP, c = 0, i = 0, j = 0, m = matrix.size(), n = matrix[0].size() ;
        while (c++ < m*n) {
            cout << matrix[i][j] << endl ;
            i += dir, j += -dir ;
            cout << "b " << i << j << endl ;
            if (max(i, j) >= min(m, n) || min(i, j) < 0) {
                if (dir == UP)  i=max(i, 0), j=min(j, n-1) ;
                else    i = min(i, m-1), j = max(j, 0) ;
                dir = -dir ;
            }
            cout << "a " << i << j << endl ;
        }
        return {} ;
    }
};
// @lc code=end

