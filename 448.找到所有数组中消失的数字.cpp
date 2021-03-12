/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> vec ;
        sort (nums.begin(), nums.end()) ;
        int idx = 1 ;
        for (auto e : nums) {
            if (e == idx)   ++ idx ;
            else if (e > idx)   addrange(vec, idx, e), idx = e+1 ;
        }
        addrange (vec, idx, nums.size()+1) ;
        return vec ;
    }
    // 左闭右开
    void addrange(vector<int> &v, int b, int e) {
        while (b < e)  v.push_back(b++) ;
    }
};
// @lc code=end

