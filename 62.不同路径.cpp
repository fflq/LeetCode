/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    // opt mem
    int uniquePaths(int m, int n) {
        vector<int> dps(102, 0) ;
        dps[1] = 1;
        /* or
        for (int i = 1; i <= m; ++ i) 
            for (int j = 1; j <= n; ++ j) {
                //move col, so add col
                dps[j] += dps[j-1];
            }
        return dps[n];
        */
        for (int j = 1; j <= n; ++ j) 
            for (int i = 1; i <= m; ++ i) {
                //move col, so add col
                dps[i] += dps[i-1];
            }
        return dps[m];
    }

    //dps[m][n] = dps[m-1][n] + dps[m][n-1]
    //dps[1][1] = 1, else 0
    int uniquePaths1(int m, int n) {
        int dps[102][102];
        memset(dps, 0, sizeof(dps));
        dps[1][1] = 1; 
        for (int i = 1; i <= m; ++ i) 
            for (int j = 1; j <= n; ++ j) {
                if (i == 1 && j == 1)   continue;
                dps[i][j] = dps[i-1][j] + dps[i][j-1];
            }
        return dps[m][n];
    }

    //calc steps
    //dps[m][n] = min(dps[m-1][n], dps[m][n-1]) + 1
    //dps[1][1] = 0, dps[1][2] = dps[2][1] = 1
    int calcSteps(int m, int n) {
        static int dps[102][102];
        memset(dps, 0x7f, sizeof(dps));

        dps[1][1] = 0;
        dps[2][1] = dps[1][2] = 1;
        for (int i = 1; i <= m; ++ i) 
            for (int j = 1; j <= n; ++ j) {
                if (i == 1 && j == 1)   continue;
                dps[i][j] = 1 + min(dps[i-1][j], dps[i][j-1]);
                printf("%d,%d %d\n", i, j, dps[i][j]);
            }
        return dps[m][n];
    }
};
// @lc code=end

int main() {
    Solution sol;
    assert(sol.uniquePaths(3,3) == 6);
    assert(sol.uniquePaths(7,3) == 28);
    return 0;
}