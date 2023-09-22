/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int b = 0, e = -1;
        for(int i = s.length()-1; i >= 0; --i) {
            //first find end idx
            if (e == -1) {
                if (s[i] != ' ') 
                    e = i;
                continue ;
            }
            //find begin idx after got end idx
            if (s[i] == ' ') {
                b = i + 1;
                break ;
            }
        }
        return e - b + 1;
    }
};
// @lc code=end

int main() {
    Solution sol;
    assert(sol.lengthOfLastWord("Hello aa World") == 5);
    assert(sol.lengthOfLastWord("   fly me   to   the moon  ") == 4);
    assert(sol.lengthOfLastWord("a   ") == 1);
    assert(sol.lengthOfLastWord("   a   ") == 1);
    assert(sol.lengthOfLastWord("   a") == 1);
    return 0;
}