/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        return validPalindrome20230928(s, 1);
    }

    bool validPalindrome20230928(string s, int delete_count) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (s[left] == s[right]) {
                ++ left;
                -- right;
            }
            else {
                if (delete_count == 0)  return false ;
                else {
                    -- delete_count;
                    return validPalindrome20230928(s.substr(left+1, right-left), delete_count) 
                        || validPalindrome20230928(s.substr(left, right-left), delete_count);
                }
                /*
                //need judge more, only next not enough
                if (delete_count == 0)  return false ;
                // delete left
                if (s[left+1] == s[right]) {
                    ++ left;
                    -- delete_count;
                }
                // delete right
                else if (s[left] == s[right-1]) {
                    -- right;
                    -- delete_count;
                }
                else    return false ;
                */
            }
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution sol;
    assert(sol.validPalindrome("abc") == false);
    assert(sol.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") == true);
    return 0;
}