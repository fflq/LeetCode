/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> perm;
        backtracking(n, k, 1, res, perm);
        return res;
    }

    void backtracking(int n, int k, int start, vector<vector<int>> &res,
            vector<int> &perm) {
        if (perm.size() == k) {
            res.push_back(perm);
            return ;
        }

        for (int i = start; i <= n; ++ i) {
            perm.push_back(i);
            //diff, not start+1 for unique
            backtracking(n, k, i+1, res, perm);
            perm.pop_back();
        }
    }
};
// @lc code=end

int main() {
    Solution sol;
    print_vvec(sol.combine(4, 2));
    return 0;
}