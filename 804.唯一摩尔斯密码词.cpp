/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<string> dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."} ;
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> sets ;
        for (auto s : words) {
            string ss = "" ;
            for (auto c : s)    ss += dict[c-'a'] ;
            sets.insert(ss) ;
        }
        return sets.size() ;
    }
};
// @lc code=end

