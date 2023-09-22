/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    //restriction: ts O(n), sp O(60000) = O(1)
    int singleNumber(vector<int>& nums) {
        //hash table
        const int offset = 30000;
        uint8_t hash[2*offset+10] = {0} ;
        auto hash_size = sizeof(hash);
        memset(hash, 0, hash_size) ;
        for (auto a : nums) {
            hash[a+offset] ++ ;
        }

        //find
        for (int i = 0; i < hash_size; ++ i) {
            if (hash[i] == 1)
                return i-offset;
        }

        assert(false);
        return -1;
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        vector<int> s{2,2,1};
        assert(sol.singleNumber(s) == 1);
    }
    {
        vector<int> s{4,1,2,1,2};
        assert(sol.singleNumber(s) == 4);
    }
    return 0;
}
