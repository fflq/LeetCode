/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int rec[26], r[26], m  ;
        memset (rec, 0, sizeof(rec)) ;

        // 初始第一个的字母统计表
        for (auto c : A[0])  ++ rec[c-'a'] ;

        for (int i = 1; i < A.size(); ++ i) {
            memset(r, 0, sizeof(r)) ;
            // 获取每个string的字母统计表
            for (auto c : A[i])  ++ r[c-'a'] ;
            // 通过r来缩小rec范围
            for (int j = 0; j < 26; ++ j) if (rec[j] > r[j]) rec[j] = r[j] ;
        }

        // 根据最终字母统计表生成
        vector<string> v ;
        for (int i = 0; i < 26; ++ i)   
            while(rec[i] --)    v.push_back(string(1, 'a'+i)) ;
        return v ;
    }
};
// @lc code=end

