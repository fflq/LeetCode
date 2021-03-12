/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        //return dailyTemperatures1(T) ;
        //return dailyTemperatures2(T) ;
        return dailyTemperatures3(T) ;
    }

    // 官方暴力next(next[e]表示e出现的最小下标，因从后往前，所以对i总是正确)
    vector<int> dailyTemperatures3(vector<int>& T) {
        vector<int> v = vector<int>(T.size(), 0) ;
        vector<int> next = vector<int>(101, INT_MAX) ;
        for (int i = T.size()-1; i >= 0; -- i) {
            int minidx = INT_MAX ;
            for (int e = T[i]+1; e < 101; ++ e) // e为温度值，非下标
                if (next[e] != INT_MAX) {
                    minidx = min(minidx, next[e] - i) ; // 遍历e-100，最小的下标
                    if (minidx == 1)    break ; // 无法更小
                }
            if (minidx != INT_MAX) v[i] = minidx ;
            next[T[i]] = i ; // 更新T[i]温度出现的最小下标
        }
        return v ;
    }

    // 单调栈
    vector<int> dailyTemperatures2(vector<int>& T) {
        vector<int> v = vector<int>(T.size(), 0) ;
        stack<int> st ;
        for (int i = 0; i < T.size(); ++ i) {
            /* 标准写法可优化
            if (st.empty() || T[st.top()] >= T[i])  st.push(i) ;
            else {
                while (!st.empty() && T[st.top()] < T[i]) // pop更新每个小于T[i]的
                    v[st.top()] = i - st.top(), st.pop() ;
                st.push (i) ;
            }
            */
            while (!st.empty() && T[st.top()] < T[i]) 
                v[st.top()] = i - st.top(), st.pop() ;
            st.push (i) ;
        }
        return v ;
    }

    // me暴力
    vector<int> dailyTemperatures1(vector<int>& T) {
        vector<int> v = vector<int>(T.size()) ;
        for (int i = T.size()-1; i >= 0; -- i) {
            for (int j = i+1; j < T.size(); ++ j) {
                if (T[j] > T[i]) { v[i] = j-i ; break ; }
                // 观察超时数据规律加的优化，居然99%通过(相同值数可利用,但要注意末尾特殊)
                if (T[j] == T[i]) { v[i] = v[j] ? j-i+v[j] : 0 ; break ; }
            }
        }
        return v ;
    }
};
// @lc code=end

