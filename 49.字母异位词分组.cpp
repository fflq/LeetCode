/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#ifdef FLQ
#include "heads.h"
#endif


// @lc code=start
class Solution {
public:
    // int[]转string还是超时，受官解启发，以频次为key，优化如下
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res ;
        map<string, vector<string>> map ;

        // 统计string的各字母频次,以频次为key直接加入队列
        for (auto s : strs) {
            string sts = string(26, '0') ;
            for (auto c : s)  ++ sts[c-'a'] ;
            map[sts].emplace_back (s) ;
        }
        for (auto e : map)  res.emplace_back(e.second) ;

        return res ;
    }

    // 超时，int[26]比较还是太慢了，要转成hash值，想不出官解的hash法，想出转int[]成string
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        vector<vector<string>> res ;
        //map<string, array<int, 26>> mapSts ;
        map<string, string> mapSts ;
        set<string> visited ;   // item是否已添加过

        // 统计string的各字母频次
        for (int i = 0; i < strs.size(); ++ i) {
            //array<int, 26> sts{} ;
            //for (auto c : strs[i])  ++ sts[c-'a'] ;
            string sts = string(26, '0') ;
            for (auto c : strs[i])  ++ sts[c-'a'] ;
            mapSts[strs[i]] = sts ;
        }

        for (int i = 0; i < strs.size(); ++ i) {
            // 跳过已入队的
            if (visited.count(strs[i]))  continue ;
            visited.insert (strs[i]) ;

            // 未入队的，则创建新队列
            vector<string> vec ;
            vec.emplace_back (strs[i]) ;

            for (int j = i + 1; j < strs.size(); ++ j) {
                // 相同sts则放同一队列
                //if (sameSts(mapSts[strs[i]], mapSts[strs[j]])) {   
                if (mapSts[strs[i]] == mapSts[strs[j]]) {
                    vec.emplace_back (strs[j]) ;
                    visited.insert (strs[j]) ;
                }
            }

            res.emplace_back (vec) ;
        }

        return res ;
    }

    // 两是否同元素
    inline bool sameSts(array<int, 26> a, array<int, 26> b) {
        for (int i = 0; i < a.size(); ++ i)  if (a[i] != b[i])   return false ;
        return true ;
    }
};
// @lc code=end

