/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 *
 * [1299] 将每个元素替换为右侧最大元素
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        //return replaceElements2(arr) ;
        return replaceElements3(arr) ;
    }

    // 官方题解，逆序单for
    vector<int> replaceElements3(vector<int>& arr) {
        int prev = -1 ;
        for (int i = arr.size()-2; i >= 0; -- i) {
            int m = max(prev, arr[i+1]) ; // m是i+2及以后中最大
            prev = arr[i] ; // 为了原地操作，要记录arr[i]信息
            arr[i] = m ;
        }
        arr[arr.size()-1] = -1 ;
        return arr ;
    }


    // 暴力
    vector<int> replaceElements2(vector<int>& arr) {
        for (int i = 0; i < arr.size()-1; ++ i)
            arr[i] = findmax(arr, i+1) ;
        arr[arr.size()-1] = -1 ;
        return arr ;
    }
    int findmax(vector<int> &arr, int beg) {
        int m = -1 ;
        for (int i = beg; i < arr.size(); ++ i)  m = max(m, arr[i]) ;
        return m ;
    }


    struct item_t { 
        int val, id ; 
        item_t(int i, int v):id(i),val(v) {}
    };
    
    // 本以为先排序后可快速查找，实际和暴力差不多
    vector<int> replaceElements1(vector<int>& arr) {
        vector<item_t> nvc ;
        for (int i = 1; i < arr.size(); ++ i)
            nvc.push_back(item_t(i, arr[i])) ;
        sort (nvc.begin(), nvc.end(), comp) ;

        for (int j = 0, i = 0; i < arr.size(); ++ i, j = 0) {
            while (j<nvc.size() && i>=nvc[j].id)  ++ j ;    // 从大到小找到第一个满足的(索引最先满足的为最大)
            if (j < nvc.size())  arr[i] = nvc[j].val ;
            else    arr[i] = -1 ;
        }
        return arr ;
    }

    static bool comp(item_t &a, item_t &b) {
        return a.val > b.val ;
    }
};
// @lc code=end

