/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int c = 0 ;
    int findTargetSumWays(vector<int>& nums, int S) {
        //dfs(nums, 0, 0, S) ;
        dfs2(nums, S) ;
        return c ;
    }

    // 非递归，居然还超时了
    void dfs2(vector<int> &nums, int target) {
        stack<pair<int, int>> st ;
        st.push({0, 0}) ;

        // 模拟递归
        while (!st.empty()) {
            int k = st.top().first ;
            int sum = st.top().second ;
            st.pop () ;

            // 边界同递归的
            if (k == nums.size()) {
                if (sum == target)  ++ c ;
                continue ;
            }

            st.push({k+1, sum+nums[k]}) ;
            st.push({k+1, sum-nums[k]}) ;
        }
    }

    void dfs(vector<int> &nums, int k, int sum, int target) {
        if (k == nums.size()) {
            if (sum == target)  ++ c ;
            return ;
        }

        dfs (nums, k+1, sum+nums[k], target) ;
        dfs (nums, k+1, sum-nums[k], target) ;
    }
};
// @lc code=end

