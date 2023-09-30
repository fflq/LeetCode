/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return do_search(nums, 0, nums.size(), target);
    }

    bool do_search(vector<int>& nums, int b, int e, int t) {
        int mid = (b + e) / 2;

        if (b >= e) return false;
        //[1]-0 not ok
        if (b == mid && nums[mid] != t) return false;
        if (nums[mid] == t) return true;
        //sorted
        //[1,0,1,1,1]-0 not ok
        //if (nums[b] <= nums[mid] && nums[mid] <= nums[e-1])
        if (nums[b] < nums[mid] && nums[mid] < nums[e-1])
            return binary_search(nums.begin()+b, nums.begin()+e, t);
        return do_search(nums, b, mid, t) || do_search(nums, mid, e, t); 
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        auto s = vector<int>{1};
        assert(sol.search(s, 0) == false);
    }
    {
        auto s = vector<int>{1,0,1,1,1};
        assert(sol.search(s, 0) == true);
    }
    {
        auto s = vector<int>{2,5,6,0,0,1,2} ;
        assert(sol.search(s, 3) == false);
    }
    {
        auto s = vector<int>{2,5,6,0,0,1,2} ;
        assert(sol.search(s, 0) == true);
    }
    return 0;
}