/*
 * @lc app=leetcode.cn id=1313 lang=cpp
 *
 * [1313] 解压缩编码列表
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res ;
        for (int i = 0; i < nums.size(); i += 2) 
            while (nums[i] --)  res.push_back(nums[i+1]) ;
        return res ;
    }
};
// @lc code=end

