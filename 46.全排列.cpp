/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include "heads.h"

// @lc code=start
class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        return permute_20231003_dfs_book(nums);
        return permute_20231003_dfs(nums);
    }


    //book思路
    //回溯直接在源数据上修改再还原
    vector<vector<int>> permute_20231003_dfs_book(vector<int>& nums) {
        vector<vector<int>> res;
        backtracking(nums, 0, res);
        return res;
    }

    void backtracking(vector<int>& nums, int idx, vector<vector<int>>& res) {
        if (idx == nums.size()-1) {
            res.push_back(nums);
            return ;
        }

        for (int i = idx; i < nums.size(); ++ i) {
            swap(nums[idx], nums[i]);
            backtracking(nums, idx+1, res);
            swap(nums[idx], nums[i]);
        }
    }


    //思路:
    //循环第一个后, 后面的就是回溯n*n*n这样
    vector<vector<int>> permute_20231003_dfs(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vector<bool> visited(nums.size(), false) ;
        for (int i = 0; i < nums.size(); ++ i) {
            dfs(nums, visited, res, perm, i) ;
        }
        return res;
    }

    void dfs(vector<int> &nums, vector<bool> &visited,  
            vector<vector<int>> &res, vector<int>& perm, int i) {
        if (visited[i])  return ;

        visited[i] = true ;
        perm.push_back(nums[i]);
        if (perm.size() == nums.size())
            res.push_back(perm);

        for (int j = 0; j < nums.size(); ++ j) {
            if (!visited[j]) {
                dfs(nums, visited, res, perm, j) ;
            }
        }

        visited[i] = false ;
        perm.pop_back();
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        vector<int> nums{1,2,3} ;
        auto res = sol.permute(nums) ;
        print_vvec(res);
    }
    return 0;
}