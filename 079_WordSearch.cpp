class Solution {
   public:
    const vector<pair<int, int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool exist(vector<vector<char>>& board, string word) {
        M = board.size();
        N = board[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));

        bool found = false;
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (board[j][i] == word[0]) {
                    found = dfs(board, j, i, visited, word, 0);
                    if (found) return true;
                }
            }
        }

        return false;
    }

    bool dfs(const vector<vector<char>>& board, int y, int x, vector<vector<bool>>& visited, string s,
             int idx) {
        if (board[y][x] != s[idx]) return false;
        if (idx == s.length() - 1) return true;

        bool found = false;
        visited[y][x] = true;
        for (auto d : directs) {
            int new_y = y + d.first;
            int new_x = x + d.second;
            if (new_y >= 0 && new_y < M && new_x >= 0 && new_x < N && visited[new_y][new_x] == false) {
                found = dfs(board, new_y, new_x, visited, s, idx + 1);
                if (found) break;
            }
        }
        visited[y][x] = false;

        return found;
    }

   private:
    int M;
    int N;
};

// DFS backtrack
// Time complexity: O(MN*3^L)
// Space complexity: O(min(MN, L))
// Runtime: 320 ms, faster than 36.52% of C++ online submissions for Word Search.
// Memory Usage: 7.5 MB, less than 23.42% of C++ online submissions for Word Search.