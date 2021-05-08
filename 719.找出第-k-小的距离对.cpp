/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 k 小的距离对
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // me先nn列出所有距离，然后不排序直接partition找第k个
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> dist ;
        for (int i = 0; i < nums.size(); ++ i)
            for (int j = i+1; j < nums.size(); ++ j)    // notice
                    dist.push_back(abs(nums[j]-nums[i])) ;

        return findMinK(dist, 0, dist.size()-1, k) ;
    }

    int findMinK(vector<int> &vec, int low, int high, int k) {
        int newi = partition(vec, low, high) ;
        cout << "ni " << newi << ", find " << low << high << k << endl << endl ;
        if (newi+1 == k)    return vec[newi] ;
        else if (newi+1 > k)  return findMinK(vec, low, newi-1, k) ;
        else    return findMinK(vec, newi+1, high, k) ;
    }

    int partition(vector<int> &vec, int low, int high) {
        //for (int i = low; i <= high; ++ i)  cout << vec[i] << ", "; cout << endl ;
        int randi = (low+high)/2 ;
        swap (vec[randi], vec[low]) ;
        int tmp = vec[low], l = low, r = high ;
        while (l < r) {
            while (l < r && vec[r] >= tmp)    -- r ;
            vec[l] = vec[r] ;
            cout << "l: " << l << ", r: " << r << endl ;

            if (l >= r)    break ;

            while (l < r && vec[l] < tmp)  ++ l ;
            vec[r] = vec[l] ;
        }
        vec[l] = tmp ;
        //for (int i = low; i <= high; ++ i)  cout << vec[i] << ", "; cout << endl ;
        return l ;
    }
};
// @lc code=end

int main() {
    // vector<int> v = {62, 100, 4} ; int k = 2 ;
    vector<int> v = {9, 10, 7, 10, 6, 1, 5, 4, 9, 8}; int k = 18 ;
    v = {0,2,2,1,1,1,0,2,2,0,1,2,2,1,2,1,1,0,0,0,1,0,0,2,2,0,1,0,1,1,1,1,0,2,0,1,2,2,0,0,2,1,2,0,2,2,0,0,1,2,2,2,1,2,0,0,0,2,2,0,2,1,2,2,1,0,2,2,1,1,1,2,0,2,2,0,0,1,0,2,0,1,1,1,1,1,1,1,2,0,2,2,2,1,1,2,2,0,1,2,1,2,0,2,0,0,2,2,0,0,1,0,2,2,1,0,2,1,0,2,2,2,0,1,0,2,1,0,2,0,1,1,2,0,0,1,1,2,2,0,2,1,2,1,2,2,1,0,0,0,0,0,2,0,1,2,0,0,0,2,1,2,2,0,2,2,0,0,1,0,0,0,2,0,2,1,0,0,0,2,1,0,1,0,2,1,2,2,0,0,2,0,2,1,0,2,1,1,0,0} ;
    k = 10000 ;
    auto obj = new Solution() ;
    cout << obj->smallestDistancePair(v, k) << endl ;
}