/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    vector<int> dirs{-1, 0, 1, 0, -1} ;
    //contains self
    //vector<int> dirs{0, 0, -1, 0, 1, 0} ;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        auto max_area = 0 ;
        for (int i = 0; i < grid.size(); ++ i) {
            for (int j = 0; j < grid[0].size(); ++ j) {
                if (grid[i][j] && !visited[i][j]) {
                    //max_area = max(max_area, dfsRecursion(grid, visited, i, j)) ;
                    max_area = max(max_area, dfsStack(grid, visited, i, j)) ;
                }
            }
        }
        return max_area;
    }

    int dfsStack(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
        auto nrow = grid.size(), ncol = grid[0].size() ;
        auto max_area = 0;

        if (x >= 0 && x < nrow && y >= 0 && y < ncol 
            && grid[x][y] && !visited[x][y]) {
            visited[x][y] = true ;
            ++ max_area ;
        }
        else {
            return max_area;
        }

        stack<pair<int, int>> st ;
        st.push({x, y});
        while (!st.empty()) {
            auto [x, y] = st.top() ; st.pop() ;
            for (int i = 0; i < dirs.size()-1; ++ i) {
                auto nx = x + dirs[i], ny = y + dirs[i+1] ;
                if (nx >= 0 && nx < nrow && ny >= 0 && ny < ncol 
                    && grid[nx][ny] && !visited[nx][ny]) {
                    visited[nx][ny] = true ;
                    //diff fro recursion
                    ++ max_area ;
                    st.push({nx, ny});
                }
            }
        }
        return max_area;
    }

    int dfsRecursion(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
        auto nrow = grid.size(), ncol = grid[0].size() ;
        auto max_area = 0;

        if (x >= 0 && x < nrow && y >= 0 && y < ncol 
            && grid[x][y] && !visited[x][y]) {
            visited[x][y] = true ;
            ++ max_area ;
        }
        else {
            return max_area;
        }

        for (int i = 0; i < dirs.size()-1; ++ i) {
            auto nx = x + dirs[i], ny = y + dirs[i+1] ;
            //judge in above not here cause [[1]]
            max_area += dfsRecursion(grid, visited, nx, ny) ;
        }
        //cout << x << "," << y << ": " << max_area << endl;
        return max_area;
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        vector<vector<int>> grid{{1,1,0,0,0},
                                 {1,1,0,0,0},
                                 {0,0,0,1,1},
                                 {0,0,0,1,1}};
        assert(sol.maxAreaOfIsland(grid) == 4) ;
    }
    return 0;
}