/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-1, m ;
        // 寻找abs最小的m
        while (l <= r) {
            m = l + (r - l) / 2 ;
            int d = dist(arr, m, x), ld = dist(arr, m-1, x) ;
            if ((d <= 0 && ld >= 0) || (d >= 0 && ld <= 0)) {
                m = abs(d) < abs(ld) ? m : m-1 ;    // dist异号处，还要判断谁更小
                break ;
            }   
            else if (d < 0 && ld < 0)   l = m+1 ;   // 关键，因为总是比较ld，故l也需m+1
            else if (d > 0 && ld > 0)   r = m-1 ;
        }
        // 然后m两边延伸k个
        l = r = m ;
        while (--k) {
            if (abs(dist(arr, l-1, x)) <= abs(dist(arr, r+1, x)))  -- l ; // l优先
            else    ++ r ;
        }
        return vector<int>(arr.begin()+l, arr.begin()+r+1) ;
    }
    inline int dist(vector<int> &arr, int m, int t) {
        if (m < 0)   return INT_MAX ;
        if (m >= arr.size())    return -INT_MAX ;  // may abs
        return (arr[m] - t) ;
        //if (m < 0 || m >= arr.size())   return INT_MAX ;
        //return abs(arr[m] - t) ;
    }
};
// @lc code=end

