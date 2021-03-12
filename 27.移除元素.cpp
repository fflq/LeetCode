/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sameNums = 0 ;  // the succession same element nums
        int len = nums.size() ;
        for (int i = len-1; i >= 0; -- i) {
            if (nums[i] == val) sameNums++ ;
            else if(sameNums > 0) {
                len -= sameNums ;
                move(nums, i+1, i+1+sameNums, len-i-1) ;
                sameNums = 0 ;
            }
        }
        // for first position
        if (sameNums>0) {
            len -= sameNums ;
            move(nums, 0, sameNums, len) ;
        }
        return len ;
    }

    // move n elements
    void move(vector<int>& nums, int to, int from, int n) {
        while (n--)
            nums[to++] = nums[from++] ;
    }
};
// @lc code=end

