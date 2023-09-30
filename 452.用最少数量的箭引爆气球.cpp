/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), 
            [](vector<int> &a, vector<int> &b){
                return a[1] < b[1];
            });
        vector<int> shots;
        for (int i = 0; i < points.size(); ++ i) {
            bool has_shotted = false;
            for (auto shot : shots) {
                if (shot >= points[i][0] && shot <= points[i][1]) {
                    has_shotted = true;
                    break;
                }    
            }
            if (has_shotted)    continue;
            shots.push_back(points[i][1]);
        }
        return shots.size();
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        vector<vector<int>> points{{10,16},{2,8},{1,6},{7,12}};
        assert(sol.findMinArrowShots(points) == 2);
    }
    {
        vector<vector<int>> points{{1,2},{3,4},{5,6},{7,8}};
        assert(sol.findMinArrowShots(points) == 4);
    }
    {
        vector<vector<int>> points{{1,2},{2,3},{3,4},{4,5}};
        assert(sol.findMinArrowShots(points) == 2);
    }
    {
        vector<vector<int>> points{{1,2}};
        assert(sol.findMinArrowShots(points) == 1);
    }
    return 0;
}