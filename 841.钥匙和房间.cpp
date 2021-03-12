/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    typedef vector<vector<int>> vvi_t ;
    int c = 0 ;
    bool seen[1001] ;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        c = rooms.size() ;
        --c, seen[0]=true, dfs (rooms, 0) ;
        return !c ? true : false ;
    }

    void dfs(vvi_t &rooms, int k) {
        for (auto e : rooms[k]) 
            if (!seen[e])   --c, seen[e]=true, dfs(rooms, e) ;
    }
};
// @lc code=end

