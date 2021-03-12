/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#ifdef FLQ
#include <iostream>
#include <cstring>
using namespace std ;
typedef string Input ;
typedef int Result ;
#endif


// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        #ifndef FLQ 
        #define cout 0&&cout
        #endif
        int maxLen = min(s.length(), (size_t)1) ;   // empty is 0, one is 1
        const size_t size = 128 ;
        char hash[size] = { 0 } ;
        for (int j, i = 0; i < s.length(); i++) {
            //memset (hash, 0, size) ;
            cout << "- " << s[i] << i << endl ;
            for (j = j; j < s.length(); j++)
            {
                cout << (bool)(hash[s[j]]) << s[j] << j << "; " ;
                if (hash[s[j]]) break ;
                else    hash[s[j]] = 1 ;
            }
            maxLen = max(maxLen, j-i) ;
            hash[s[i]] = 0 ;    // slide window
            cout << maxLen << endl ;
        }
        return maxLen ;
    }
};
// @lc code=end


#ifdef FLQ
int main() {
   Solution solution = Solution() ;
   Input s ;
   while (cin >> s) {           
       Result res = solution.lengthOfLongestSubstring(s) ;
       cout << res << endl ;
   }
   return 0 ;
}
#endif