/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // 二分法模板1
    int firstBadVersion1(int n) {
        int l = 1, r = n, m ;
        while (l <= r) {
            m = l + (r - l)/2 ;
            if (isBadVersion(m)) {
                if (!isBadVersion(m-1))  return m ;
                else    r = m - 1 ;
            } 
            else if (!isBadVersion(m))  l = m + 1 ;    
        }
        return -1 ;
    }

    // 二分法模板2
    int firstBadVersion(int n) {
        int l = 1, r = n, m ;
        while (l < r) { // 结束条件 l == r
            m = l + (r - l)/2 ;
            if (isBadVersion(m))    r = m ; // r始终指向错误版本
            else    l = m + 1 ;    
        }
        if (isBadVersion(l) && !isBadVersion(l-1))  return l ;
        else    return -1 ;
    }
};
// @lc code=end

