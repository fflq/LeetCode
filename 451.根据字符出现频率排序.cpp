/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    struct st {
        char ch ; 
        int c ;
        st(char ch, int c): ch(ch), c(c) {}
    } ;
    string frequencySort(string s) {
        int dict[256] ;
        memset (dict, 0, sizeof(dict)) ;

        // 统计频率
        for (auto c : s)    ++ dict[c] ;

        // 构造结构体存到vec中
        vector<struct st> vec ;
        for (int j = 0; j < 256; ++ j) {
            if (dict[j]) {   
                struct st t = {(char)j, dict[j]} ;
                vec.push_back(t) ;
            }
        }

        // 对vec排序
        sort (vec.begin(), vec.end(), comp) ;

        // 按序输出
        string ss = "" ;
        for (auto e : vec)  ss += string(e.c, e.ch) ;

        return ss ;
    }
    static bool comp(struct st &a, struct st &b) {
        return a.c > b.c ;
    }
};
// @lc code=end

