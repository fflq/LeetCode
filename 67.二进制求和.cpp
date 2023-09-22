/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        //distinguish long and short string
        string &long_str = a, &short_str = b ;
        if (long_str.length() < short_str.length()) {
            swap(long_str, short_str);
        }
        //avoid highest carry overflow
        long_str = "0" + long_str;

        int short_str_idx = short_str.length() - 1;
        int long_str_idx = long_str.length() - 1;
        for(; short_str_idx >= 0; -- short_str_idx, -- long_str_idx) {
            int n = long_str[long_str_idx] + short_str[short_str_idx] - '0' - '0';
            long_str[long_str_idx] = '0' + (n % 2);
            long_str[long_str_idx-1] += (n / 2);
        }
        while (long_str_idx > 0) {
            int n = long_str[long_str_idx] - '0';
            long_str[long_str_idx] = '0' + (n % 2);
            long_str[long_str_idx-1] += (n / 2);
            -- long_str_idx;
        }
        //remove add highest char
        auto s = (long_str[0] == '0') ? long_str.substr(1, long_str.length()-1) : long_str ;
        cout << s << endl;
        return s; 
    }
};
// @lc code=end

int main() {
    Solution sol;
    assert(sol.addBinary("1111", "1111") == "11110");
    assert(sol.addBinary("11", "1") == "100");
    assert(sol.addBinary("1010", "1011") == "10101");
    return 0;
}