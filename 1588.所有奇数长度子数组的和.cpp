/*
 * @lc app=leetcode.cn id=1588 lang=cpp
 *
 * [1588] 所有奇数长度子数组的和
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int s = 0 ;
        for (int range = 1; range <= arr.size(); range += 2)
            s += sum(arr, range) ;
        return s ;
    }
    int sum(vector<int> &arr, int range=1) {
        int s = 0 ;
        for (int i = 0; i+range <= arr.size(); ++ i)
            // sum of i ~ i+range-1
            for (int j = i; j < i+range; ++ j)
                s += arr[j] ;
        return s ;
    }
};
// @lc code=end

