/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */
#ifdef FLQ
#include "heads.h"
#endif
/*
BFS获取路径长度的两种办法：
1. 在每层结尾添加标记元素到queue中
2. 每次for了size次，累加长度
*/

// @lc code=start
class Solution {
public:
    int cc ;
    unordered_set<string> vist ;
    unordered_set<string> ddends ;  // 不然会超时
    // 四维的迷宫
    int openLock(vector<string>& deadends, string target) {
        vist.clear () ;
        ddends.clear () ;
        ddends.insert (deadends.begin(), deadends.end()) ;

        string s = "0000" ;
        //return BFS_20200204 (s, target) ;
        return BFS_20200204_2 (s, target) ;
        //int n = 0 ;
        //return DFS (s, target, n) ;
    }

    // DFS暂没法做，穷尽所有然后取最小的方法不行，因为可以无限长，不好找结束条件
    int DFS(string s, string target, int n) {
        //cout << s << " " << n << endl ;
        int c = INT_MAX ;
        for (int i = 0; i < 4; ++ i) {
            if (s[i] == target[i])  continue ;
            for (int j = -1; j < 2; j += 2) {
                int op[4] = { 0, 0, 0, 0 } ;
                op[i] = j ;
                s = getNewNum(s, op) ;
                cout << s << " " ;
                if (vist.find(s) == vist.end()) {
                    if (s == target) { return n ; }   
                    //vist.insert (s) ;
                    if (!ddends.count(s))   c = min(c, DFS(s, target, n+1)) ;
                }
            }
        }
        cout << endl ;
        return c ;
    }


    // BFS_20200204_2，根据题解优化初始的写法
    int BFS_20200204_2(string s, string target) {
        queue<string> que ;
        vist.insert (s) ;
        que.push (s) ;
        int n = 0 ;

        while (!que.empty()) {
            int size = que.size() ; // 不能放进for里，因为size()是变化的
            for (int i = 0; i < size; ++ i) { // 替代了oneLevelEnd作用
                string s = que.front() ;
                que.pop () ;

                if (s == target)    return n ;
                if (!ddends.count(s)) 
                    for (int i = 0; i < 4; ++ i) 
                        for (int j = -1; j < 2; j += 2) {
                            string ss = s; ss[i] = '0' + (j + ss[i]-'0' + 10)%10 ;
                            pushNew (que, ss) ;
                        }
            }
            ++ n ;
        }

        return -1 ;
    }


    // BFS_20200204，初始写法加上看题解修改
    // 关键点，用于区分各层次，从而得到bfs路径长度(或者可用size法,见题解评论)
    const string oneLevelEnd = "aaaa" ;  
    // 迭代BFS不好统计路径长度
    int BFS_20200204(string s, string target) {
        queue<string> que ;
        vist.insert (s) ;
        que.push (s) ;
        que.push (oneLevelEnd) ;
        int n = 0 ;
        int op[4] = { 0, 0, 0, 0 } ;

        while (!que.empty()) {
            string s = que.front() ;
            que.pop () ;

            if (s == target)    return n ;
            else if (s == oneLevelEnd) {
                cout << endl << n << endl ;
                ++ n ;
                if (!que.empty())   que.push (oneLevelEnd) ; // 关键，既添加层标记，也避免队空时添加层标记
            }   
            else if (!ddends.count(s)) {
                for (int i = 0; i < 4; ++ i) 
                    for (int j = -1; j < 2; j += 2) {
                        memset (op, 0, sizeof(op)) ;
                        op[i] = j ;
                        string ss = getNewNum(s, op) ;
                        pushNew (que, ss) ;
                    }
            }
        }
        return -1 ;
    }
    // 根据op上下旋转，得到新的数
    inline string getNewNum(string str, int op[4]) {
        int s = atoi(str.c_str()) ;
        for (int i = 3, k; i >= 0; -- i) {  // 关键，因为k是低位
            k = s % 10 ; s /= 10 ;
            str[i] = '0' + (op[3-i]+10+k) % 10 ;    
        }
        return str ;
    }
    inline void pushNew(queue<string> &que, string s) {
        if (!vist.count(s) && !ddends.count(s)) 
            //cout << s << ", ",
            que.push (s), vist.insert (s) ;
    }
};
// @lc code=end


int main() {
    int op[4] = { 0, 1, 0, 0 } ;
    cout << Solution().getNewNum("2010", op) << endl ;
    return 0 ;
}

