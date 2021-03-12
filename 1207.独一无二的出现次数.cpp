/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int rec[2001], nrec[2001] ;
        memset (rec, 0, sizeof(rec)) ;
        memset (nrec, 0, sizeof(nrec)) ;

        // 统计各数字出现的次数
        for (auto c : arr)  ++ rec[1000+c] ;

        // 统计上面次数的次数
        for (int i = 0; i < 2001; ++ i)
            if (rec[i]) {
                // 是否有相同次数，即>1
                if (nrec[rec[i]])   return false ;
                else    ++ nrec[rec[i]] ;
            }

        return true ;
    }
};
// @lc code=end

