/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    // 二分模板2
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, h = letters.size(), m ;
        while (l < h) {
            m = l + (h - l) / 2 ;
            if (letters[m] <= target)    l = m + 1 ;
            else    h = m ; 
        }
        return letters[l % letters.size()] ;
    }

    // 二分模板1
    char nextGreatestLetter1(vector<char>& letters, char target) {
        int l = 1, h = letters.size()-1, m ;
        while (l <= h) {
            m = l + (h - l) / 2 ;
            if (letters[m] > target && letters[m-1] <= target)  return letters[m] ;
            else if (letters[m] > target)   h = m - 1 ;
            else    l = m + 1 ;
        }
        return letters[0] ;
    }
};
// @lc code=end

