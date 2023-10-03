/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        return findCircleNum_20231003_union(isConnected);
        return findCircleNum_20231003_dfs(isConnected);
    }

    int findParent(vector<int> &union_set, int i) {
        while (union_set[i] != i)
            i = union_set[i];
        return i;
    }

    void Union(vector<int> &union_set, int i, int j) {
        int pi = findParent(union_set, i), pj = findParent(union_set, j);
        if (pi != pj)   union_set[pi] = pj;
    }

    //并查集
    int findCircleNum_20231003_union(vector<vector<int>>& isConnected) {
        vector<int> union_set(isConnected.size());
        for (int i = 0; i < union_set.size(); ++ i)  union_set[i] = i;

        for (int i = 0; i < isConnected.size(); ++ i) {
            for (int j = 0; j < isConnected[0].size(); ++ j) {
                if (isConnected[i][j]) {
                    Union(union_set, i, j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < union_set.size(); ++ i) {
            if (union_set[i] == i)  ++ count;
        }
        return count;
    }


    //思路: 不是地图,是邻接表
    int findCircleNum_20231003_dfs(vector<vector<int>>& isConnected) {
        auto conn_count = 0;
        vector<bool> visited(isConnected.size(), false);
        for (int i = 0; i < isConnected.size(); ++ i) {
            if (!visited[i]) {
                dfs(isConnected, visited, i) ;
                ++ conn_count;
                //print_vvec(isConnected);
            }
        }

        //cout << conn_count << endl ;
        return conn_count;
    }

    vector<int> dirs{-1, 0, 1, 0, -1};

    void dfs(vector<vector<int>> &isConnected, vector<bool>& visited, int row) {
        auto nrows = isConnected.size(), ncols = isConnected[0].size() ;
        visited[row] = true;
        stack<int> st;
        st.push(row);

        while (!st.empty()) {
            auto row = st.top() ; st.pop() ;
            for (int i = 0; i < ncols; ++ i) {
                if (isConnected[row][i] && !visited[i]) {
                    st.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        vector<vector<int>> isConnected{{1,0,0,1},
                                        {0,1,1,0},
                                        {0,1,1,1},
                                        {1,0,1,1}} ;
        assert(sol.findCircleNum(isConnected) == 1) ;
    }
    {
        vector<vector<int>> isConnected{{1,1,0},{1,1,0},{0,0,1}} ;
        assert(sol.findCircleNum(isConnected) == 2) ;
    }
    return 0;
}