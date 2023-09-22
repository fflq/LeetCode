/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //hash table
        unordered_map<int, int> hash ;
        for (auto a : nums) {
            hash[a] ++ ;
            if (hash[a] > nums.size()/2)
                return a ;
        }
        return -1 ;
    }
};
// @lc code=end

