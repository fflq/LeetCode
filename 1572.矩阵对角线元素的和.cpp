/*
 * @lc app=leetcode.cn id=1572 lang=cpp
 *
 * [1572] 矩阵对角线元素的和
 */

// @lc code=start
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int s = 0, m = mat.size() ;
        for (int i = 0; i < m; ++ i)   
            s += (mat[i][i]+mat[i][m-i-1]) ;
        if (m%2)    s -= mat[m/2][m/2] ;
        return s ;
    }
};
// @lc code=end

