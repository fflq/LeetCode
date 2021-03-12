/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int c = 0 ;
        for (int i = 0; i < nums.size(); ++ i)
            for (int j = i+1; j < nums.size(); ++ j)
                if (nums[i] == nums[j]) ++ c ;
        return c ;
    }
};
// @lc code=end

