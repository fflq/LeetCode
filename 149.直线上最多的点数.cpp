/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 优化，因为每次都是以i为根，所以不用考虑截距b，只需斜率k
    // 同LC447思想及模板，先找个根i，然后遍历(i,*)的次数
    int maxPoints(vector<vector<int>>& pts) {
        if (pts.size() < 2)   return pts.size() ;

        int maxc = 0, len = pts.size() ;
        map<double, int> mapSts ;  // <k,count>
        for (int i = 0, onemax = 0; i < len; ++ i) {
            for (int j = 0; j < len; ++ j) {
                if (i != j) {
                    double k = getK(pts[i], pts[j]) ;
                    if (!mapSts.count(k))   mapSts[k] = 2 ; // 因为是两个点
                    else    ++ mapSts[k] ;
                    onemax = max(onemax, mapSts[k]) ;
                }
            }
            maxc = max(maxc, onemax) ;   // 全局最大数
            mapSts.clear() ;
        }
        return maxc ;
    }
    // 获取两个点斜率
    double getK(vector<int> &a, vector<int> &b) {
        return (b[0]-a[0]) ? 1.0*(b[1]-a[1])/(b[0]-a[0]) : INFINITY ;
    }

    // 同LC447思想及模板，先找个根i，然后遍历(i,*)的次数
    // 不同点在于，此处使用pair作为key
    int maxPoints1(vector<vector<int>>& pts) {
        if (pts.size() < 2)   return pts.size() ;

        int maxc = 0, len = pts.size() ;
        map<pair<float, float>, int> mapSts ;  // <y=kx+b,count>
        pair<float, float> f ;
        for (int i = 0; i < len; ++ i) {
            for (int j = 0; j < len; ++ j) {
                if (i != j) {
                    f = getFuncEqu(pts[i], pts[j]) ;
                    if (!mapSts.count(f))   mapSts[f] = 2 ; // 因为是两个点
                    else    ++ mapSts[f] ;
                }
            }
            // 以i为根的所有直线，穿过点的最大数
            int m = 0 ; for (auto e : mapSts)   m = max(m, e.second) ;
            maxc = max(maxc, m) ;   // 全局最大数
            mapSts.clear() ;
        }
        return maxc ;
    }
    // 获取两个点生成的直线方程式的k和b: y2-y1=k(x2-x1),b[1]-a[1]=k(b[0]-a[0])
    pair<float, float> getFuncEqu(vector<int> &a, vector<int> &b) {
        pair<float, float> f ;
        f.first = (b[0]-a[0]) ? 1.0*(b[1]-a[1])/(b[0]-a[0]) : INFINITY ;
        f.second = isinf(f.first) ? 0 : a[1]-a[0]*f.first ;
        return f ;
    }
};
// @lc code=end

