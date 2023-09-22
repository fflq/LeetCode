/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        int sum = 0;
        vector<char> vec;
        while (columnNumber) {
            auto n = (columnNumber % 26) - 1;
            n = (n + 26) % 26;
            char c = 'A' + n;
            vec.push_back(c);
            //wrong in 26 = 'A'
            //columnNumber /= 26;
            columnNumber = (columnNumber - 1) / 26;
        }

        reverse(vec.begin(), vec.end());
        string s(vec.data(), vec.size());

        return s;
    }
};
// @lc code=end

int main() {
    Solution sol;
    assert(sol.convertToTitle(701) == "ZY");
    assert(sol.convertToTitle(1) == "A");
    assert(sol.convertToTitle(28) == "AB");
    assert(sol.convertToTitle(2147483647) == "FXSHRXW");
    return 0;   
}