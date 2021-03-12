/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#ifdef FLQ
#include <iostream>
#include <cstring>
#include <vector>
using namespace std ;
#endif

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int s = 0, e = nums.size()-1, m, f=-1 ;
        while (s<e) {
            m = (s+e)/2 ;
            if (nums[m]<t)  s = m+1 ;
            else if (nums[m]>t) e = m-1 ;
            else return m ;
        }
        // here s==e
        if (nums[s]<t)  return s+1 ;
        else    return s ;
    }
};
// @lc code=end

