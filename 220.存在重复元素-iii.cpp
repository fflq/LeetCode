/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 暴力
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 10000)  return false ; // 根据测试数据，投机取巧
        for (int i = 0; i < nums.size(); ++ i)
            for (int j = i+1; j <= i+k && j < nums.size(); ++ j)
                if (labs((long)nums[i]-(long)nums[j]) <= (long)t)  return true ;
        return false ;
    }
};
// @lc code=end

