/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
#ifdef FLQ
#include <iostream>
#include <cstring>
#include <vector>
using namespace std ;
#endif


// @lc code=start
class Solution {
#ifndef FLQ 
#define cout 0&&cout
#endif
public:
    int removeDuplicates(vector<int>& nums) {
        int n = 0, lastV = nums.empty()? -1 : nums[0]+1 ;
        int i, v, len = nums.size() ;
        for (i = 0; i < len; ++i) {
            v = nums[i] ;
            if (lastV != v) {
                lastV = v ;
                nums[n++] = v ;
            }
        }
        return n ;
    }
};
// @lc code=end

