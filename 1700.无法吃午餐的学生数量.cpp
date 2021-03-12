/*
 * @lc app=leetcode.cn id=1700 lang=cpp
 *
 * [1700] 无法吃午餐的学生数量
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sw) {
        int size = st.size(), top = 0, front = 0, dislike = 0 ;

        while (dislike < size-top) {    // 剩余所有人都不喜欢则退出
            if (sw[top] == st[front]) { 
                ++ top ; ++ front ;
                dislike = 0 ;
            }
            else { // 不喜欢则换下一人
                st.push_back (st[front++]) ;
                ++ dislike ;
            }
        }

        return size-top ;
    }
};
// @lc code=end

