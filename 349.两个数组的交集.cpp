/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 题未给出数据范围，用set而不是int[]
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res, st = set<int>(nums1.begin(), nums1.end()) ;
        for (auto e : nums2)
            if (st.count(e))
                res.insert(e) ;
        return vector<int>(res.begin(), res.end()) ;
    }
};
// @lc code=end

