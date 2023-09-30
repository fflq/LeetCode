/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    bool judgeContained(unordered_map<char, int>& sub_freqs, 
        unordered_map<char, int>& t_freqs) {
        for (auto [c, n] : t_freqs) {
            //freqs not enough
            if (n > sub_freqs[c]) {
                return false;
            }
        }
        return true;
    }

    //TLE, add sp opt for "aaaaaaaaaaaaaa..."
    //really reason is judgeContained() not use ref before
    string minWindow(string s, string t) {
        unordered_map<char, int> t_freqs;
        for (auto c : t)    ++ t_freqs[c];

        unordered_map<char, int> sub_freqs;
        string sub_string(s.size()+1,'0');
        int shortest_l = 0, shortest_r = INT_MAX;
        for (int l = 0, r = 0; r < s.size(); ++ r) {
            //add new s[r] freqs
            ++ sub_freqs[s[r]];
            if (sub_freqs.size() < t_freqs.size())    continue;   

            //judge if s[l:r] contains t
            while (l <= r && (r-l+1 >= t.size())) {
                //1. not contain, break and move r to find contained
                if (!judgeContained(sub_freqs, t_freqs))  break;
                //2. has contained, loop record shortest one
                if ((r-l) < (shortest_r-shortest_l)) {
                    shortest_l = l;
                    shortest_r = r;
                }
                //2.2 loop try move l to decrease sub string
                -- sub_freqs[s[l]];
                ++ l;
            }
        }

        return (shortest_r < s.size()) ? 
            s.substr(shortest_l, shortest_r-shortest_l+1) : "" ;
    }

    
    bool judgeContained(vector<int> sub_freqs, unordered_map<int, int> t_freqs) {
        for (auto [c, n] : t_freqs) {
            //freqs not enough
            if (n > sub_freqs[c]) {
                return false;
            }
        }
        return true;
    }

    string minWindow1(string s, string t) {
        unordered_map<int, int> t_freqs;
        for (auto c : t) {
            //t_freqs[c] = t_freqs.count(c) ? t_freqs[c]+1 : 1;
            ++ t_freqs[c];
        }   

        string sub_string(s.size()+1,'0');
        vector<int> sub_freqs(256, 0);
        int shortest_l = 0, shortest_r = INT_MAX;
        for (int l = 0, r = 0; r < s.size(); ++ r) {
            //add new s[r] freqs
            ++ sub_freqs[s[r]];

            //judge if s[l:r] contains t
            while (l <= r && (r-l+1 >= t.size())) {
                //1. not contain, break and move r to find contained
                if (!judgeContained(sub_freqs, t_freqs))  break;
                //2. has contained, loop record shortest one
                if ((r-l) < (shortest_r-shortest_l)) {
                    shortest_l = l;
                    shortest_r = r;
                }
                //2.2 loop try move l to decrease sub string
                -- sub_freqs[s[l]];
                ++ l;
            }
        }

        return (shortest_r < s.size()) ? 
            s.substr(shortest_l, shortest_r-shortest_l+1) : "" ;
    }
};
// @lc code=end

int main() {
    Solution sol;
    assert(sol.minWindow("aa", "aa") == string("aa"));
    assert(sol.minWindow("a", "a") == string("a"));
    assert(sol.minWindow("ADOBECODEBANC", "ABC") == string("BANC"));
    assert(sol.minWindow("a", "aa") == string(""));
    return 0;
}
