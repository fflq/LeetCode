/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0, j = matrix.size()-1; i < matrix.size()/2; ++ i, -- j) 
            swap (matrix[i], matrix[j]) ;
        
        for (int i = 0; i < matrix.size(); ++ i)
            for (int j = 0; j < i; ++ j)
                swap (matrix[i][j], matrix[j][i]) ;
    }
};
// @lc code=end

