/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    typedef vector<vector<int>> vvi_t ;
    int m, n, oldC, newC ;
    vvi_t floodFill(vvi_t& image, int sr, int sc, int newColor) {
        m = image.size(), n = image[0].size() ;
        oldC = image[sr][sc], newC = newColor ;

        bfs (image, sr, sc, newColor) ;
        return image ;
    }

    void bfs(vvi_t& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> que ; // 满足条件的才会放进que
        set<pair<int, int>> sets ;  // 因为考虑oldC==newC时，会死循环，直接set可能不够快，但是最清晰
        image[sr][sc] = newC ;
        que.push({sr, sc}) ;
        sets.insert({sr, sc}) ;
        
        while (!que.empty()) {
            sr = que.front().first, sc = que.front().second, que.pop() ;
            pushCheck (image, que, sets, sr-1, sc) ;
            pushCheck (image, que, sets, sr+1, sc) ;
            pushCheck (image, que, sets, sr, sc-1) ;
            pushCheck (image, que, sets, sr, sc+1) ;
        }
    }

    bool inRange(int r, int c) { return r>=0 && r<m && c>=0 && c<n ; }

    void pushCheck (vvi_t &image, queue<pair<int, int>> &que, set<pair<int, int>> &sets, 
                    int r, int c) {
        if (inRange(r, c) && image[r][c]==oldC && !sets.count({r, c}))
            image[r][c]=newC, que.push({r, c}), sets.insert({r, c}) ;
    }
};
// @lc code=end

