/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    string getSeqStr(int beg, int end) {
        if (beg == end)    return to_string(beg) ;
        return to_string(beg) + "->" + to_string(end) ;
    }

    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty())    return res;

        int seq_beg = nums[0], seq_end = nums[0];
        for (int i = 1; i < nums.size(); ++ i) {
            // in one seq
            if (nums[i] == seq_end + 1) {
                seq_end = nums[i];
                continue;
            }

            // not in one seq
            res.push_back(getSeqStr(seq_beg, seq_end));
        
            // new seq
            seq_beg = seq_end = nums[i];
        }
        res.push_back(getSeqStr(seq_beg, seq_end));

        return res;
    }
};
// @lc code=end

