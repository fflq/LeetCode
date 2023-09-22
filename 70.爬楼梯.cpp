/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    /*
    int climbStairs(int n) {
        if (n == 0 || n == 1)  return 1 ;
        return climbStairs(n-1) + climbStairs(n-2);
    }
    */
    int climbStairs(int n) {
        static int dp[50] = {1, 1};
        if (!dp[n]) {
            for(int i = 2; i <= n; ++i) {
                dp[i] = dp[i-1] + dp[i-2] ;
            }
        }
        return dp[n];
    }
};
// @lc code=end

int main() {
    clock_t start = clock();
    assert(Solution().climbStairs(2) == 2);
    assert(Solution().climbStairs(3) == 3);
    assert(Solution().climbStairs(44) == 1134903170);
    cout << (clock() - start)/CLOCKS_PER_SEC << endl;
    return 0;
}