/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto &row : A)
            for (int i = 0, j = row.size()-1; i <= j; ++ i, -- j) {
                int temp = 1-row[i] ;
                row[i] = 1-row[j] ;
                row[j] = temp ;
            }
        return A ;
    }
};
// @lc code=end

