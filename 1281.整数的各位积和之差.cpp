/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> vec ;
        while (n)   vec.push_back(n%10), n /= 10 ;
        int m = 1, s = 0 ;
        for (auto e : vec) {
            if (m)  m *= e ;
            s += e ;
        }
        return m - s ;
    }
};
// @lc code=end

