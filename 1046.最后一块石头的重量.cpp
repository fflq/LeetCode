/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    void updateMaxHeap(vector<int> &vec) {
        for (int i = vec.size()/2; i >= 0; -- i)    
            adjustMaxHeap(vec, i, vec.size()) ;
    }
    void adjustMaxHeap(vector<int> &vec, int k, int end) {
        int left = 2*k+1, right = 2*k+2, bigidx = k ;
        // 先选出三者间最大值得索引
        if (left < end && vec[left] > vec[bigidx])   bigidx = left ;
        if (right < end && vec[right] > vec[bigidx])   bigidx = right ;
        if (bigidx != k) {
            swap (vec[bigidx], vec[k]) ;
            adjustMaxHeap (vec, bigidx, end) ;
        }
    }
    void insertMaxHeap(vector<int> &vec, int num) {
        vec.push_back (num) ;
        updateMaxHeap (vec) ;
    }
    int getMax(vector<int> &vec) {
        int num = vec.front() ;
        vec.front() = vec.back() ;
        vec.pop_back() ;
        adjustMaxHeap (vec, 0, vec.size()) ;
        return num ;
    }

    int lastStoneWeight(vector<int>& stones) {
        updateMaxHeap(stones) ;
        while (stones.size() > 1) {
            for (auto e : stones) cout << e << " " ; cout << endl ;
            int a = getMax(stones), b = getMax(stones) ;
            //cout << a << "," << b << endl ;
            if (a != b) insertMaxHeap(stones, abs(a-b)) ;
        }
        return stones.empty() ? 0 : stones.front() ;
    }
};
// @lc code=end

