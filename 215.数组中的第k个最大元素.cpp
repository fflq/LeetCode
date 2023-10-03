/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest_20231003(nums, k) ;
        return findKthLargest_heap(nums, k) ;
    }


    //TLE for sp case 40/41
    int findKthLargest_20231003(vector<int>& nums, int k) {
        return quick_k_sort(nums, 0, nums.size()-1, nums.size()-k+1);
    }

    //思路:
    //快直到找到索引k-1就返回
    int quick_k_sort(vector<int>& nums, int left, int right, int minest_k) {
        if (left > right)  return -1;
        auto l = left, r = right, key = nums[left];
        while (l < r) {
            while (l < r && nums[r] >= key)   -- r;
            nums[l] = nums[r];
            while (l < r && nums[l] <= key)   ++ l;
            nums[r] = nums[l];
        }
        nums[l] = key;
        if (l == minest_k-1)   return nums[l];
        else if (l < minest_k-1)   return quick_k_sort(nums, l+1, right, minest_k);
        else    return quick_k_sort(nums, left, l-1, minest_k);
    }


    // 原地最小堆实现
    // 取前k建最小堆，后size-k依次和堆顶比较，大于堆顶则交换，堆化
    // 此时堆为最大前k，堆顶最小故为第k大
    int findKthLargest_heap(vector<int>& nums, int k) {
        int heapSize = k ;
        buildMinHeap(nums, heapSize) ;
        //print_vec (nums) ;
        for (int i = k; i < nums.size(); ++ i) {
            if (nums[0] < nums[i]) {
                swap(nums[0], nums[i]); 
                minHeapify(nums, 0, heapSize) ;
            }
            //print_vec (nums) ;
        }
        return nums[0] ;
    }

    void minHeapify(vector<int> &nums, int node, size_t heapSize) {
        int lchild = 2*node+1, rchild = 2*node+2, smallest = node ;
        if (lchild < heapSize && nums[lchild] < nums[smallest]) 
            smallest = lchild ;
        if (rchild < heapSize && nums[rchild] < nums[smallest]) 
            smallest = rchild ;
        if (smallest != node) {
            swap(nums[node], nums[smallest]); 
            minHeapify(nums, smallest, heapSize) ;
        }  
    }

    void buildMinHeap(vector<int> &nums, size_t heapSize) {
        for (int i = heapSize/2; i >= 0; -- i)  
            minHeapify(nums, i, heapSize) ;
    }
};
// @lc code=end


int main() {
    Solution sol;
    {
        vector<int> s = {3,2,1,5,6,4} ;
        assert (sol.findKthLargest(s, 2) == 5) ;
    }
    {
        vector<int> s = {3,2,3,1,2,4,5,5,6} ;
        assert (sol.findKthLargest(s, 4) == 4) ;
    }
    return 0;
}
