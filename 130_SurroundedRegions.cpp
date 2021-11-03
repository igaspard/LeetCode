class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        M = board.size();
        N = board[0].size();
        // Start from the outside of the board, mark the connected points as good points
        for (int j = 0; j < M; ++j) {
            dfs(board, j, 0);
            dfs(board, j, N - 1);
        }
        for (int i = 0; i < N; ++i) {
            dfs(board, 0, i);
            dfs(board, M - 1, i);
        }

        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (board[j][i] == 'O')
                    board[j][i] = 'X';
                else if (board[j][i] == 'G')
                    board[j][i] = 'O';
                else
                    continue;
            }
        }
    }

   private:
    int M, N;
    const vector<pair<int, int>> directs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(vector<vector<char>>& board, int y, int x) {
        if (y < 0 || y >= M || x < 0 || x >= N || board[y][x] != 'O') return;

        board[y][x] = 'G';

        for (auto d : directs) dfs(board, y + d.first, x + d.second);
    }
};

// dfs to find the good point instead of finding the bad point
// Runtime: 4 ms, faster than 99.93% of C++ online submissions for Surrounded Regions.
// Memory Usage: 10.3 MB, less than 35.83% of C++ online submissions for Surrounded Regions.

class Solution {
   public:
    void bfsBoundary(int i, int j, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        board[i][j] = 'E';

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int x = cur.first, y = cur.second;

            // check adj
            if (x != 0 && board[x - 1][y] == 'O') {  // left
                q.push(make_pair(x - 1, y));
                board[x - 1][y] = 'E';
            }
            if (x != m - 1 && board[x + 1][y] == 'O') {  // right
                q.push(make_pair(x + 1, y));
                board[x + 1][y] = 'E';
            }
            if (y != 0 && board[x][y - 1] == 'O') {  // up
                q.push(make_pair(x, y - 1));
                board[x][y - 1] = 'E';
            }
            if (y != n - 1 && board[x][y + 1] == 'O') {  // down
                q.push(make_pair(x, y + 1));
                board[x][y + 1] = 'E';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (!m) return;

        int n = board[0].size();

        for (int i = 0; i < m; i++) {  // check left, right
            if (board[i][0] == 'O') bfsBoundary(i, 0, board);
            if (board[i][n - 1] == 'O') bfsBoundary(i, n - 1, board);
        }
        for (int i = 0; i < n; i++) {  // check top and bottom
            if (board[0][i] == 'O') bfsBoundary(0, i, board);
            if (board[m - 1][i] == 'O') bfsBoundary(m - 1, i, board);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'E')
                    board[i][j] = 'O';
            }
        }
    }
};
