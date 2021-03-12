/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include "heads.h"

// @lc code=start
class Solution {
#ifndef FLQ 
#define cout 0&&cout
#endif
public:
    int maxSubArray(vector<int>& n) {
        //f(i), [0,i]上最大的靠右的连续子数组和
        //f(i) = max(f(i-1)+ai, ai) ;
        int smax = n[0], s = n[0], len = n.size() ;
        for (int i = 1; i < len; ++ i) {                                
            s = max(s+n[i], n[i]) ;
            smax = max(s, smax) ;
        }
        return smax ;
    }
};
// @lc code=end


int main() {
   Solution solution = Solution() ;
   vector<int> n = {-2,1,-3,4,-1,2,1,-5,4} ;
       int res = solution.maxSubArray(n) ;
       cout << res << endl ;
       getchar () ;
   return 0 ;
}