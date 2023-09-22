/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    map<char, int> val_map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    //sps
    map<string, int> sp_val_map = {
        {"IV", 4},
        {"IX", 9},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900},
    };

    int romanToInt(string s) {
        int val = 0;
        for(int i = 0; i < s.length();) {
            auto sp_str = s.substr(i,2);
            if (sp_val_map.count(sp_str)) {
                val += sp_val_map[sp_str];
                i += 2;
            }
            else {
                val += val_map[s[i]];
                ++ i;
            }
        }

        return val;
    }
};
// @lc code=end

int main() {
    Solution sol;
    assert(sol.romanToInt("III") == 3);
    assert(sol.romanToInt("IV") == 4);
    assert(sol.romanToInt("IX") == 9);
    assert(sol.romanToInt("LVIII") == 58);
    assert(sol.romanToInt("MCMXCIV") == 1994);
    return 0;
}