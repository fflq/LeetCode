/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++ i)
            for (int j = 0; j < board[0].size(); ++ j)
                if (board[i][j] == word[0]) {
                    //leak casue error
                    board[i][j] -= 60;
                    auto ret = backtracking(board, word, i, j, 0);
                    board[i][j] += 60;
                    if (ret) return true;
                }
        return false;
    }

    vector<int> dirs{-1, 0, 1, 0, -1};

    bool backtracking(vector<vector<char>>& board, string& word, 
            int x, int y, int idx) {
        if (idx == word.size()-1) {
            return true;
        }

        for (int i = 0; i < dirs.size()-1; ++ i) {
            auto nx = x + dirs[i], ny = y + dirs[i+1];
            if (nx >= 0 && nx < board.size() 
                && ny >= 0 && ny < board[0].size()
                && board[nx][ny] == word[idx+1]) {
                //cout << nx << ", " << ny << endl;
                board[nx][ny] -= 60;
                auto ret = backtracking(board, word, nx, ny, idx+1);
                board[nx][ny] += 60;
                if (ret)    return true;
            }
        }
        //print_vvec(board);

        return false;
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        vector<vector<char>> board{{'a','a'}};
        cout << sol.exist(board, "aaa") << endl;
    }
    {
        vector<vector<char>> board{{'A','B','C','E'},
                                   {'S','F','C','S'},
                                   {'A','D','E','E'}};
        cout << sol.exist(board, "ABCCED") << endl;
        cout << sol.exist(board, "SEE") << endl;
        cout << sol.exist(board, "ABCB") << endl;
    }
    return 0;
}