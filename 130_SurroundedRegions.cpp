class Solution {
public:
    void bfsBoundary(int i, int j, vector< vector<char> > &board) {
        int m = board.size();
        int n = board[0].size();

        queue< pair<int, int> > q;
        q.push(make_pair(i, j));
        board[i][j] = 'E';

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int x = cur.first, y = cur.second;

            // check adj
            if (x!=0 && board[x-1][y] == 'O') { // left
                q.push(make_pair(x-1, y));
                board[x-1][y] = 'E';
            }
            if (x!=m-1 && board[x+1][y] == 'O') { // right
                q.push(make_pair(x+1, y));
                board[x+1][y] = 'E';
            }
            if (y!=0 && board[x][y-1] == 'O') { // up
                q.push(make_pair(x, y-1));
                board[x][y-1] = 'E';
            }
            if (y!=n-1 && board[x][y+1] == 'O') { // down
                q.push(make_pair(x, y+1));
                board[x][y+1] = 'E';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (!m) return;

        int n = board[0].size();

        for (int i = 0; i < m; i++) { // check left, right
            if (board[i][0] == 'O')
                bfsBoundary(i, 0, board);
            if (board[i][n-1] == 'O')
                bfsBoundary(i, n-1, board);
        }
        for (int i = 0; i < n; i++) { // check top and bottom
            if (board[0][i] == 'O')
                bfsBoundary(0, i, board);
            if (board[m-1][i] == 'O')
                bfsBoundary(m-1, i, board);
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
