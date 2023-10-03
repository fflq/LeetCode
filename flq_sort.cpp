#include "heads.h"

using veci = vector<int>;


//wrong
void quick_sort1(veci& nums, int left, int right) {
    if (left >= right) return ;
    //need retain k, so use left+1
    auto k = nums[left], l = left+1, r = right ;
    while (l < r) {
        while (l < r && nums[l] <= k)   ++ l ;
        while (l < r && nums[r] >= k)   -- r ;
        if (l < r)  swap(nums[l], nums[r]);
    }
    if (-- l < 0)   return;
    swap(nums[left], nums[l]);
    quick_sort1(nums, left, l-1) ;
    quick_sort1(nums, l+1, right) ;
}

void quick_sort(veci& nums, int left, int right) {
    if (left >= right) return ;
    auto k = nums[left], l = left, r = right ;
    while (l < r) {
        //must right first, because k is nums[left]
        while (l < r && nums[r] >= k)   -- r ;
        nums[l] = nums[r];
        while (l < r && nums[l] <= k)   ++ l ;
        nums[r] = nums[l];
    }
    nums[l] = k;
    quick_sort(nums, left, l-1) ;
    quick_sort(nums, l+1, right) ;
}


void merge_sort(veci& nums, int left, int right, veci& temp) {
    if (left >= right)  return;

    //split
    auto mid = (left + right) / 2;
    auto l1 = left, r1 = mid, l2 = mid+1, r2 = right;
    merge_sort(nums, l1, r1, temp);
    merge_sort(nums, l2, r2, temp);

    //combine
    auto i = left;
    while (l1 <= r1 || l2 <= r2) {
        if (l1 <= r1 && l2 <= r2) {
            if (nums[l1] < nums[l2])    temp[i++] = nums[l1++];
            else    temp[i++] = nums[l2++];
        }
        else {
            if (l1 <= r1)   temp[i++] = nums[l1++];
            else    temp[i++] = nums[l2++];
        }
    }

    for (int i = left; i <= right; ++ i)    nums[i] = temp[i];
}


void insertion_sort(veci& nums) {
    auto min_num = INT_MIN;
    for (int i = 0; i < nums.size(); ++ i) {
        //auto key = nums[i] ;
        //insert(use swap impl here for simp) to correct pos
        for (int j = i; j > 0; -- j) {
            if (nums[j] < nums[j-1])
                swap(nums[j], nums[j-1]);
            else
                break;
        }
    }
}


void bubble_sort(veci& nums) {
    for (int i = 0; i < nums.size(); ++ i) {
        auto swaped = false;
        for (int j = i + 1; j < nums.size(); ++ j) {
            if (nums[j] < nums[i]) {
                swap(nums[j], nums[i]);
                swaped = true;
            }
        }
        // already sorted, end
        if (!swaped)    break;
    }
}


void selection_sort(veci& nums) {
    for (int i = 0; i < nums.size(); ++ i) {
        auto min_num_idx = i;
        for (int j = i; j < nums.size(); ++ j) {
            if (nums[min_num_idx] > nums[j]) {
                min_num_idx = j;
            }
        }
        swap(nums[i], nums[min_num_idx]);
    }
}


int main() {
    vector<int> nums_orig = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    vector<int> temp(nums_orig.size());
    print_vec(nums_orig);
    {
        auto nums = nums_orig;
        sort(nums.begin(), nums.end());
        print_vec(nums);
    }
    {
        auto nums = nums_orig;
        quick_sort(nums, 0, nums.size()-1);
        print_vec(nums);
    }
    {
        auto nums = nums_orig;
        merge_sort(nums, 0, nums.size()-1, temp);
        print_vec(nums);
    }
    {
        auto nums = nums_orig;
        insertion_sort(nums);
        print_vec(nums);
    }
    {
        auto nums = nums_orig;
        bubble_sort(nums);
        print_vec(nums);
    }
    {
        auto nums = nums_orig;
        selection_sort(nums);
        print_vec(nums);
    }
    
#if 0
#endif
}