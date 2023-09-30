/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    // offical ref, use closed
    // 思路: [1,2,3,4,5]写出五种情况,然后找规律分析
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] < nums[r])  r = m;
            else if (nums[m] > nums[r]) l = m + 1;
            else    -- r;
            // not else    ++ l;
        }
        return nums[l];
    }


    /*
        1. 不断比较min_num至循环结束
        2. [2,3,4,5,1], mid左边有序, 若[0]<[sz-1]则右, 否则左
        3. [5,1,2,3,4], mid右边有序, 左
        wrong
    */
    int do_findMin20230930(vector<int>& nums, int left, int right) {
        int min_num = INT_MAX;
        while (left < right) {
            auto mid = (left + right) / 2;
            min_num = min(min_num, nums[mid]);
            //right-side is order
            if (nums[mid] < nums[right]) {
                right = mid;
            }
            //left-side is order
            else if (nums[mid] > nums[left]) {
                if (nums[right] < nums[left])
                    left = mid + 1;
                else
                    right = mid;
            }
            else {
                min_num = min(do_findMin20230930(nums, left, mid),
                    do_findMin20230930(nums, mid+1, right));
            }
        }
        cout << min_num << endl;
        return min_num;
    }

    int findMin20230930(vector<int>& nums) {
        return do_findMin20230930(nums, 0, nums.size()-1);
    }


    // wrong，[10,1,10,10,10]
    int findMin1(vector<int>& nums) {
        int l = 0, h = nums.size()-1, m ;
        while (l <= h) {
            m = l + (h - l) / 2 ;
            if (m > 0 && nums[m] < nums[m-1])    return nums[m] ;
            else if (nums[m] >= max(nums[l], nums[h]))   l = m + 1 ;
            else h = m - 1 ;
        }
        return nums.front() ;
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        vector<int> v{10,10,10,1,10};
        assert(sol.findMin(v) == 1) ;
    }
    {
        vector<int> v{1,1,3,1};
        assert(sol.findMin(v) == 1) ;
    }
    {
        vector<int> v{1,3,5};
        assert(sol.findMin(v) == 1) ;
    }
    {
        vector<int> v{2,2,2,0,1};
        assert(sol.findMin(v) == 0) ;
    }
    return 0;
}
