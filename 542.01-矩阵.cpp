/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    typedef vector<vector<int>> vvi_t ;
    int m, n ;

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size() ;

        for (int i = 0; i < m; ++ i) 
            for (int j = 0; j < n; ++ j)
                matrix[i][j] = matrix[i][j] ? bfs(matrix, i, j) : 0 ;
        return matrix ;
    }

    int bfs(vvi_t& matrix, int sr, int sc) {
        queue<pair<int, int>> que ; // 满足条件的才会放进que
        set<pair<int, int>> sets ;  // 因为考虑oldC==newC时，会死循环，直接set可能不够快，但是最清晰
        que.push({sr, sc}) ;
        sets.insert({sr, sc}) ;
        
        int c = 0 ;
        while (!que.empty()) {
            int size = que.size() ;
            while (size --) {
                sr = que.front().first, sc = que.front().second, que.pop() ;
                if (!matrix[sr][sc]) return c ;
                pushCheck (matrix, que, sets, sr-1, sc) ;
                pushCheck (matrix, que, sets, sr+1, sc) ;
                pushCheck (matrix, que, sets, sr, sc-1) ;
                pushCheck (matrix, que, sets, sr, sc+1) ;
            }
            ++ c ;
        }
        return c ;
    }

    bool inRange(int r, int c) { return r>=0 && r<m && c>=0 && c<n ; }

    void pushCheck (vvi_t &matrix, queue<pair<int, int>> &que, set<pair<int, int>> &sets, 
                    int r, int c) {
        if (inRange(r, c) && !sets.count({r, c}))
            que.push({r, c}), sets.insert({r, c}) ;
    }
};
// @lc code=end

