/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include "heads.h"
#ifdef FLQ
#endif

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        digits[0] += 1 ;
        int c = 0;
        for(auto &d : digits) {
            auto n = d + c;
            d = n % 10;
            c = n / 10;
            if (!c) break ;
        }
        if (c)  digits.push_back(c) ;
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
// @lc code=end

void flqmain() {
    vector<int> vec;
    vec = {9,9} ; print_vec(Solution().plusOne(vec));
    vec = {1,2,3} ; print_vec(Solution().plusOne(vec));
    vec = {9} ; print_vec(Solution().plusOne(vec));
}