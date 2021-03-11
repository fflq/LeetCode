/*
 * @lc app=leetcode.cn id=1656 lang=cpp
 *
 * [1656] 设计有序流
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class OrderedStream {
public:
    vector<string> vec ;
    int ptr ;
    OrderedStream(int n) {
        vec = vector<string>(n+2, "") ; // 1-n, n+1为哨兵
        ptr = 1 ;   // index from 1
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> v ;

        vec[idKey] = value ;
        while (vec[ptr] != "")  v.push_back(vec[ptr++]) ;

        return v ;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end

