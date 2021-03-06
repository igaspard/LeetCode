class Solution {
   public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrace(board, 0);
        return ans;
    }

    void backtrace(vector<string> &board, int row) {
        if (row == board.size()) {
            ans.emplace_back(board);
            return;
        }

        for (int col = 0; col < board[row].size(); ++col) {
            if (!isValid(board, row, col)) continue;

            board[row][col] = 'Q';
            backtrace(board, row + 1);
            board[row][col] = '.';
        }
    }

    bool isValid(const vector<string> &board, int row, int col) {
        // check up
        for (int j = 0; j < row; ++j)
            if (board[j][col] == 'Q') return false;
        // check left up
        for (int j = row - 1, i = col - 1; j >= 0 && i >= 0; --j, --i)
            if (board[j][i] == 'Q') return false;
        // check right up
        for (int j = row - 1, i = col + 1; j >= 0 && i < board.size(); --j, ++i)
            if (board[j][i] == 'Q') return false;

        return true;
    }
};
// backtrace
// Your runtime beats 94.53 % of cpp submissions
// Your memory usage beats 89.61 % of cpp submissions (7.2 MB)