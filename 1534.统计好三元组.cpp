/*
 * @lc app=leetcode.cn id=1534 lang=cpp
 *
 * [1534] 统计好三元组
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        //return countGoodTriplets1(arr, a, b, c) ;
        return countGoodTriplets2(arr, a, b, c) ;
    }

    // 剪枝
    int countGoodTriplets2(vector<int>& arr, int a, int b, int c) {
        int n = 0 ;
        for (int i = 0; i < arr.size(); ++ i)
            for (int j = i+1; j < arr.size(); ++ j)
                if (abs(arr[i]-arr[j]) <= a)
                    for (int k = j+1; k < arr.size(); ++ k) 
                        if (abs(arr[j]-arr[k]) <= b && abs(arr[i]-arr[k]) <= c)
                            ++ n ;
        return n ;
    }

    // 暴力
    int countGoodTriplets1(vector<int>& arr, int a, int b, int c) {
        int n = 0 ;
        for (int i = 0; i < arr.size(); ++ i)
            for (int j = i+1; j < arr.size(); ++ j)
                for (int k = j+1; k < arr.size(); ++ k) {
                    if (abs(arr[i]-arr[j]) <= a
                        && abs(arr[j]-arr[k]) <= b
                        && abs(arr[i]-arr[k]) <= c)
                        ++ n ;
                }
        return n ;
    }
};
// @lc code=end

