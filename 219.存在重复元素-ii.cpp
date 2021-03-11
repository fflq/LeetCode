/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 官解，动态窗口+哈希
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> st ;
        for (int i = 0; i < nums.size(); ++ i) {
            if (st.count(nums[i]))  return true ;
            st.insert (nums[i]) ;

            if (st.size() > k) st.erase(nums[i-k]) ;    // 保持窗口大小k
        }
        return false ;
    }

    // 暴力超时
    bool containsNearbyDuplicate1(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++ i)
            for (int j = i+1; j <= i+k && j < nums.size(); ++ j)
                if (nums[i] == nums[j])  return true ;
        return false ;
    }
};
// @lc code=end

