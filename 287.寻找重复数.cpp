/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // set法
    int findDuplicate(vector<int>& nums) {
        set<int> st ;
        for (auto e : nums)
            if (!st.count(e))   st.insert(e) ;
            else    return e ;
        return -1 ;
    }
};
// @lc code=end

