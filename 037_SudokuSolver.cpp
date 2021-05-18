class Solution {
   public:
    void solveSudoku(vector<vector<char>> &board) { backtrack(board, 0, 0); }

    bool backtrack(vector<vector<char>> &board, int j, int i) {
        if (i == N) return backtrack(board, j + 1, 0);

        if (j == M) return true;

        if (board[j][i] != '.') return backtrack(board, j, i + 1);

        for (char ch = '1'; ch <= '9'; ++ch) {
            if (isValid(board, j, i, ch) == false) continue;
            board[j][i] = ch;
            if (backtrack(board, j, i + 1)) return true;
            board[j][i] = '.';
        }

        return false;
    }

    bool isValid(vector<vector<char>> &board, int y, int x, char ch) {
        for (int i = 0; i < 9; ++i) {
            // check row
            if (board[y][i] == ch) return false;
            // check col
            if (board[i][x] == ch) return false;
        }

        // check 3x3
        int base_y = y / 3 * 3;
        int base_x = x / 3 * 3;
        for (int j = base_y; j < base_y + 3; ++j)
            for (int i = base_x; i < base_x + 3; ++i)
                if (board[j][i] == ch) return false;

        return true;
    }

   private:
    const int M = 9;
    const int N = 9;
};

// backtrack
