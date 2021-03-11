/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
 */

// @lc code=start
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int c = 0 ;
        for (auto e : nums)
            c += (isEven(e) ? 1 : 0) ;
        return c ;
    }

    inline bool isEven(int n) {
        int c = 0 ;
        while (n)   ++ c, n /= 10 ;
        return c%2==0 ? true : false ;
    }
};
// @lc code=end

