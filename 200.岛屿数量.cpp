/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    typedef vector<vector<char>> vvc_t ;
    queue<pair<int, int>> que ;
    //set<int> sets ; char sets[300][300] ; 直接改值1为0，省了sets
    int m, n ; 
    // 四个方向
    int numIslands(vvc_t& grid) {
        m = grid.size(), n =grid[0].size() ;
        int  c = 0 ;
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (grid[i][j] == '1')  BFS (grid, i, j), ++ c ;
        return c ;
    }

    void BFS(vvc_t &grid, int r, int c) {
        //que = queue<pair<int, int>>() ;    // fast clear
        que.push ({r, c}) ;
        grid[r][c] = 0 ;

        while (!que.empty()) {
            r = que.front().first ;
            c = que.front().second ;
            que.pop () ;

            pushWithCheck (grid, r-1, c) ;  // 上
            pushWithCheck (grid, r+1, c) ;  // 下
            pushWithCheck (grid, r, c-1) ;  // 左 
            pushWithCheck (grid, r, c+1) ;  // 右
        }
    }

    inline bool isInRange(int i, int j) { return i>=0 && i<m && j>=0 && j<n ; }
    inline void pushWithCheck(vvc_t &grid, int r, int c) {  // 好家伙，忘了加&，怎优化都超时
        if (isInRange(r, c) && grid[r][c]=='1') // 在范围内，且为1，且未访问过
            que.push ({r, c}), grid[r][c] = 0 ; // 不在这加0会超时
    }

};
// @lc code=end

