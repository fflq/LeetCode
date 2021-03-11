/*
 * @lc app=leetcode.cn id=1266 lang=cpp
 *
 * [1266] 访问所有点的最小时间
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 切比雪夫距离
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sum = 0 ;
        for (int i = 0; i < points.size()-1; ++ i) 
            sum += calTime(points[i], points[i+1]) ;
        return sum ;
    }

    // 思路不对，参考题解，因横竖和斜着用时同，故为横竖最大值即可
    int calTime(vector<int> &src, vector<int> &dst) {
        int dx = dst[0] - src[0] ;
        int dy = dst[1] - src[1] ;
        return max(abs(dx), abs(dy)) ;

        // abs(dx),abs(dy)，谁小，先斜着对齐睡
        int xt = dx, yt = dy - xt ; // 先斜着对齐x，再平移y
        if (abs(dy) < abs(dx)) {    // 先斜着对齐y，再x
            yt = dy, xt = dx - yt ;
        }

        return abs(xt) + abs(yt) ;
    }
};
// @lc code=end

