/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    using vvb = vector<vector<bool>> ;
    //思路:
    //左上往上走标记1, 左上往左走标记2, 同时有标记12的为结果
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        auto nrow = heights.size(), ncol = heights[0].size() ;

        vvb visited1(nrow, vector<bool>(ncol, false));
        vvb visited2(nrow, vector<bool>(ncol, false));
        for (int i = 0; i < nrow; ++ i) {
            dfs(heights, visited1, i, 0) ;
            dfs(heights, visited2, i, ncol-1) ;
        }
        for (int i = 0; i < ncol; ++ i) {
            dfs(heights, visited1, 0, i) ;
            dfs(heights, visited2, nrow-1, i) ;
        }
        //print_vvec(visited1);
        //print_vvec(visited2);

        //visited1 && visited2
        vector<vector<int>> res;
        for (int i = 0; i < nrow; ++ i)
            for (int j = 0; j < ncol; ++ j) {
                if (visited1[i][j] && visited2[i][j])
                    res.push_back({i, j});
            }
        return res;
    }

    vector<int> dirs{-1, 0, 1, 0, -1};
    void dfs(vector<vector<int>>& nums, vvb &visited, int x, int y) {
        auto nrow = nums.size(), ncol = nums[0].size() ;
        if (x < 0 || x >= nrow || y < 0 || y >= ncol)  return ;

        visited[x][y] = true ;
        for (int i = 0; i < dirs.size()-1; ++ i) {
            int nx = x + dirs[i], ny = y + dirs[i+1] ;
            if (nx >= 0 && nx < nrow && ny >= 0 && ny < ncol 
                && !visited[nx][ny]
                && nums[nx][ny] >= nums[x][y]) {
                visited[nx][ny] = true ;
                dfs(nums, visited, nx, ny) ;
            }
        }
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        vector<vector<int>> nums = {
            {1,2,2,3,5},
            {3,2,3,4,4},
            {2,4,5,3,1},
            {6,7,1,4,5},
            {5,1,1,2,4}
        };
        auto res = sol.pacificAtlantic(nums) ;
        print_vvec(res) ;
    }
    return 0;
}