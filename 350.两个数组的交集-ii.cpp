/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort (nums1.begin(), nums1.end()) ;
        sort (nums2.begin(), nums2.end()) ;
        vector<int> vec ;
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size(); ) {
            if (nums1[i] == nums2[j]) vec.push_back(nums1[++ j, i ++]) ;
            else if (nums1[i] < nums2[j])   ++ i ;
            else    ++ j ;
        }
        return vec ;
    }
};
// @lc code=end

