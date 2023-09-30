/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [](vector<int> &a, vector<int> &b){
                return a[1] < b[1];
            });
        int latest_end = INT_MIN;
        int remove_cnt = 0;
        for (int i = 0; i < intervals.size(); ++ i) {
            if (intervals[i][0] >= latest_end) {
                latest_end = intervals[i][1];
            }
            else {
                ++ remove_cnt;
            }
        }
        return remove_cnt;
    }
};
// @lc code=end

