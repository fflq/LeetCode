/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 说是并查集，实际是最小生成树，先跳过
    int minCostConnectPoints(vector<vector<int>>& pts) {
        auto ufs = new UFS(pts.size()) ;
        int sum = 0 ;
        for (int i = 0; i < pts.size(); ++ i) {
            int mindist = INT_MAX, minid = -1 ;
            for (int j = 0; j < pts.size(); ++ j) {
                //已同根的也算数，不然被迫选远点，例子出错[[0,0],[1,1],[1,0],[-1,1]]
                //if (i != j && ufs->ancestor(i) != ufs->ancestor(j)) {
                if (i != j) {
                    int dist = getDist(pts[i], pts[j]) ;
                    if (dist < mindist)  minid=j, mindist=dist ;
                }
            }
            if (minid != -1) {  
                cout << i << "," << minid << endl ;
                // 因为上面去掉检查，故这里已是同根的，避免重复累加
                if (ufs->ancestor(i) != ufs->ancestor(minid))   sum += mindist ;
                ufs->unionn (i, minid) ;    // 连接距离i最近的点
            }
        }
        return sum ;
    }
    inline int getDist(vector<int> &a, vector<int> &b) {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]) ;
    }

class UFS {
public :
    int *father = nullptr ;
    int size ;
    UFS(int n): size(n) { init(n) ; }
    ~UFS() { deinit() ; } 

    int *init(int n) { 
        father = new int[n] ;
        for (int i = 0; i < n; ++ i)    father[i] = i ; 
        return father ;
    }
    void deinit() { if (father)  delete father ; }

    int ancestor(int e) {
        int x = e, y = e, z ;
        while (x != father[x])  x = father[x] ;
        while (y != father[y])  z = y, y = father[y], father[z] = x ;
        return x ;
    }

    int unionn(int a, int b) {
        a = ancestor(a), b = ancestor(b) ;
        if (a != b) father[b] = a ;
        return a ;
    }
};

};
// @lc code=end

