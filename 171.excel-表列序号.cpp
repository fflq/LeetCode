/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        uint64_t sum = 0;
        uint64_t _pow = 1;
        for (auto p = columnTitle.end()-1; p >= columnTitle.begin(); -- p) {
            sum += _pow * (*p - 'A' + 1);
            _pow *= 26;
        }
        return (int)sum;
    }
};
// @lc code=end

int main() {
    Solution sol;
    assert(sol.titleToNumber("FXSHRXW") == 2147483647);
    assert(sol.titleToNumber("A") == 1);
    assert(sol.titleToNumber("AB") == 28);
    assert(sol.titleToNumber("ZY") == 701);
    return 0;
}