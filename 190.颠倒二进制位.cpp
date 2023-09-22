/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bin(n) ;
        size_t sz = bin.size();
        for (int i = 0; i < sz/2; ++ i) {
            //swap(bin[i], bin[sz-1-i]) ;
            if (bin[i] != bin[sz-1-i]) {
                bin[i].flip();
                bin[sz-1-i].flip();
            }
        }
        return bin.to_ullong();
    }
};
// @lc code=end

int main() {
    Solution sol;
    assert(sol.reverseBits(43261596) == 964176192) ;
    assert(sol.reverseBits(4294967293) == 3221225471) ;
    return 0 ;
}