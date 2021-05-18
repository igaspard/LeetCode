class Solution {
public:
    vector<vector<string>> ans;
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return ans.size();
    }

    void backtrack(vector<string> &board, int row) {
        if (board.size() == row) {
            ans.emplace_back(board);
            return;
        }
        
        for (int col = 0; col < board[row].size(); ++col) {
            if (isValid(board, row, col) == false) continue;
            
            board[row][col] = 'Q';
            backtrack(board, row + 1);
            board[row][col] = '.';
        }
    }
    
    bool isValid(vector<string> &board, int row, int col) {
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

