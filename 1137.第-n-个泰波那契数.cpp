/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    //TLE need table
    int tribonacci(int n) {
        static int dps[50] = {0, 1, 1};
        // cause dps[0]==0 not uninitial
        if (!dps[n] && n) { 
            dps[n] = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
        }
        return dps[n];
    }
};
// @lc code=end

int main() {
    Solution sol;
    assert(sol.tribonacci(4) == 4);    
    assert(sol.tribonacci(25) == 1389537);    
    return 0;
}