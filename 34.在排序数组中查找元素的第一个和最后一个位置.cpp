/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return searchRange20230929(nums, target) ;
        return searchRange1(nums, target) ;
        return searchRange2(nums, target) ;
    }


    vector<int> searchRange20230929(vector<int>& nums, int target) {
        //std::*, lb >= target, ub > target
        //auto lb = lower_bound(nums.begin(), nums.end(), target) ;
        //auto ub = upper_bound(nums.begin(), nums.end(), target) ;
        auto lb = x_lower_bound(nums.begin(), nums.end(), target) ;
        auto ub = x_upper_bound(nums.begin(), nums.end(), target) ;
        if (lb == nums.end() || *lb != target)
            return {-1, -1};
        return {static_cast<int>(lb-nums.begin()), 
                static_cast<int>(ub-nums.begin()-1)};
    }


    //overwrite std:*
    using viit = vector<int>::iterator ;
    viit x_lower_bound(viit begit, viit endit, int target) {
        viit midit;
        while (begit < endit) {
            midit = (int)(endit-begit)/2 + begit ;
            if (*midit >= target) // diff
                endit = midit ;
            else 
                begit = midit + 1 ;
        }
        //begit == endit
        return begit;
    }
    
    viit x_upper_bound(viit begit, viit endit, int target) {
        viit midit;
        while (begit < endit) {
            midit = (int)(endit-begit)/2 + begit ;
            if (*midit > target) // diff
                endit = midit ;
            else 
                begit = midit + 1 ;
        }
        return begit;
    }


    // 二分模板2，放弃
    vector<int> searchRange2(vector<int>& nums, int t) {
        int l = 0, h = nums.size(), m ;
        while (l < h) {
            m = l + (h - l) / 2 ;
            if (nums[m] < t)    l = m+1 ;
            else    h = m ;
        }
        return {-1, -1} ;
    }


    // 二分模板1
    vector<int> searchRange1(vector<int>& nums, int t) {
        int l = 0, h = nums.size()-1, m ;
        while (l <= h) {
            m = l + (h - l) / 2 ;
            if (nums[m] == t)   break ;
            else if (t < nums[m])   h = m-1 ;
            else    l = m+1 ;
        }

        if (l <= h) {
            l = h = m ;
            while (h+1<nums.size() && nums[h+1]==t)    ++ h ;
            while (l-1>=0 && nums[l-1]==t)    -- l ;
            return {l, h} ;
        }
        else 
            return {-1, -1} ;
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        vector<int> v{5,7,7,8,8,10} ;
        vector<int> r{3,4};
        assert(sol.searchRange(v, 8) == r) ;
    }
    {
        vector<int> v{5,7,7,8,8,10} ;
        vector<int> r{-1,-1};
        assert(sol.searchRange(v, 6) == r) ;
    }
    return 0;
}
