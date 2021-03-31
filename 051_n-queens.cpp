/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        backtrace(ans, board, 0);

        return ans;
    }

    void backtrace(vector<vector<string>> &ans, vector<string> &board, int row) {
        if (row == board.size()) {
            ans.emplace_back(board);
            return;
        }

        const int N = board[row].size();
        for (int col = 0; col < N; ++col) {
            if (!isValid(board, row, col)) continue;

            board[row][col] = 'Q';
            backtrace(ans, board, row+1);
            board[row][col] = '.';
        }
    }

    bool isValid(const vector<string> &board, int row, int col) {
        const int N = board.size();
        for (int i = 0; i < row; ++i)
            if (board[i][col] == 'Q') return false;
        
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; --i, ++j)
            if (board[i][j] == 'Q') return false;

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 'Q') return false;

        return true;
    }
};
// @lc code=end

// backtrace
// Your runtime beats 94.53 % of cpp submissions
// Your memory usage beats 89.61 % of cpp submissions (7.2 MB)