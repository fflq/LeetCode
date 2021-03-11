/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 同(2)，只不过改实时计算，为秋后算账
    int numberOfBoomerangs(vector<vector<int>>& pts) {
        map<int, int> mapSts ; // dist与count的map
        int len = pts.size(), n = 0 ;
        for (int i = 0; i < len; ++ i) {
            for (int j = 0; j < len; ++ j) 
                if (i != j) {
                    int dist = getDist(pts[i], pts[j]) ;
                    if (!mapSts.count(dist))    mapSts[dist] = 1 ;
                    else    ++ mapSts[dist] ;
                } 
            // 即P(m,2)=m*(m-1)
            for (auto e : mapSts)   n += e.second * (e.second-1) ;
            mapSts.clear () ;   // 每次循环记录当前i的(i,*)距离次数统计
        }
        return n ;
    }

    // 看题解后优化，问的是(i,j)与(i,k)等距，故只要遍历(i,*)的即可
    int numberOfBoomerangs2(vector<vector<int>>& pts) {
        map<int, int> mapSts ; // dist与count的map
        int len = pts.size(), n = 0 ;
        for (int i = 0; i < len; ++ i) {
            for (int j = 0; j < len; ++ j) 
                if (i != j) {
                    int dist = getDist(pts[i], pts[j]) ;
                    if (!mapSts.count(dist))    mapSts[dist] = 1 ;
                    else {
                        int m = mapSts[dist] ;
                        // 原有同dist共m个(i,*)，以i为根，三元组后两个则是在m中任取2个，即P(m,2) ;
                        // 同理现在变成m+1个，即P(m+1,2)，新增多的个数为P(m+1,2)-P(m,2)=2m
                        n += 2*m ;  
                        mapSts[dist] = m+1 ;
                    }
                } 
            mapSts.clear () ;   // 每次循环记录当前i的(i,*)距离次数统计
        }
        return n ;
    }

    // 暴力超时，打表优化仍超时
    int numberOfBoomerangs1(vector<vector<int>>& pts) {
        map<int, int> mapDist ;// 索引a*len+b与dist的map
        int len = pts.size(), n = 0 ;
        for (int i = 0; i < len; ++ i)
            for (int j = 0; j < len; ++ j) {
                if (i != j)  mapDist[i*len+j] = getDist(pts[i], pts[j]) ;
            }
        for (int i = 0; i < len; ++ i) {
            for (int j = 0; j < len; ++ j) {
                if (i == j)  continue ;
                for (int k = 0; k < len; ++ k) {
                    if (i == k || j == k)  continue ;
                    //if (getDist(pts[i], pts[j]) == getDist(pts[i], pts[k]))
                    if (mapDist[i*len+j] == mapDist[i*len+k])
                        ++ n ;
                }
            }
        }
        return n ;
    }
    inline int getDist(vector<int> a, vector<int> b) {
        return pow(b[0]-a[0], 2) + pow(b[1]-a[1], 2) ;
    }
};
// @lc code=end

