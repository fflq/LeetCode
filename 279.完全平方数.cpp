/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 贪心+BFS
    // 思路：第一步有1~sqrt(n)条路径，第二步有1~sqrt(n-i*i)条路径(i为第一步所选)
    // 超时关键：不在于打表，而在于添加到queue的数有重复，要用set筛一遍
    int sqtab[101] = { 0, 0 } ; // 记录范围内平方表
    int anstab[10001] = { 0 } ; // 记录答案表
    int numSquares(int n) {
        for (int i = sqrt(n)+1; i > 0; -- i) {    
            if (sqtab[i] != 0)  break ; // 动态增加平方表
            sqtab[i] = i*i ;
        } 
        //memset (anstab, 0, sizeof(anstab)) ;

        int a = n, aa, c = 0 ;
        queue<int> que ;
        que.push (a) ;
        while (!que.empty()) {
            unordered_set<int> sets ;
            for (int k = 0, s = que.size(); k < s; ++ k) {
                a = que.front() ; que.pop() ; 
                //aa = sqrt(a) ;

                if (anstab[a] != 0) { anstab[n] = anstab[a]+n ; return anstab[n] ; }
                if (a == 0) { anstab[n] = c ; return c ; }
                //for (int i = aa; i > 0; -- i) que.push (a-i*i) ;  // 每次有1~sqrt(n)种路径选择
                for (int i = 1; sqtab[i] <= a; ++ i)  
                    if (!sets.count(a-sqtab[i]))    
                        que.push(a-sqtab[i]), sets.insert (a-sqtab[i]) ;  // 关键点，避免重复项，可解决超时问题
            }
            ++ c ;
        }

        return -1 ;
    }
};
// @lc code=end

