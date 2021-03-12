/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    // 官解二分法，二分一定有一边是有序序列，判断其中是否存在，不在则对另一无序队列重复此过程
    int search(vector<int>& nums, int t) {
        int l = 0, r = nums.size()-1, m ;
        while (l <= r) {
            m = (l + r) / 2 ;
            if (t == nums[m])  return m ;
            if (nums[l] <= nums[m]) {   // 左子列有序
                // t在左子列范围内则选左，否则继续迭代右子列
                if (nums[l] <= t && t < nums[m])  return bsearch(nums, l, m-1, t) ;
                else    l = m + 1 ;
            }
            else {  // 右子列有序
                if (nums[m] < t && t <= nums[r])  return bsearch(nums, m+1, r, t) ;
                else    r = m - 1 ;
            }
        }
        return -1 ;
    }    
    int bsearch(vector<int> &nums, int l, int r, int t) {
        while (l <= r) {
            int m = (l + r) / 2 ;
            if (nums[m] == t)  return m ;
            else if (t > nums[m])  l = m + 1 ;
            else    r = m - 1 ;
        }
        return -1 ;
    }
};
// @lc code=end

