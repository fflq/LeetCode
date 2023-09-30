/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    // offical
    // only record ends
    vector<int> partitionLabels(string s) {
        int ends[26];
        for (int pos = 0; pos < s.size(); ++ pos)
            ends[s[pos]-'a'] = pos;

        vector<int> res ;
        int start = 0, end = 0;
        for (int pos = 0; pos < s.size(); ++ pos) {
            end = max(end, ends[s[pos]-'a']);
            if (pos == end) {
                res.push_back(end - start + 1);
                start = pos+1;
            }
        }

        return res;
    }

    using Range = vector<int>;
    vector<int> partitionLabels1(string s) {
        vector<Range> ranges(26, Range(2, -1)) ;
        for (int pos = 0; pos < s.size(); ++ pos) { 
            auto& range = ranges[s[pos] - 'a'] ;
            range[0] = (range[0] == -1) ? pos : min(range[0], pos) ;
            range[1] = max(range[1], pos);
        }
        // no need sort

        int left = 0, right = 0;
        vector<int> res ;
        for (int pos = 0; pos < s.size(); ++ pos) {
            auto cur_left = ranges[s[pos]-'a'][0];
            auto cur_right = ranges[s[pos]-'a'][1] ;
            
            //new
            if (cur_left > right) {
                res.push_back(right - left + 1) ;
                left = cur_left;
                right = cur_right;
                continue;
            }

            //cross
            left = min(left, cur_left);
            right = max(right, cur_right);
        }        
        res.push_back(right - left + 1);

        return res;
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        auto s = vector<int>{9,7,8};
        assert(sol.partitionLabels("ababcbacadefegdehijhklij") == s);
    }
    assert(sol.partitionLabels("eccbbbbdec") == vector<int>{10});
    return 0;
}