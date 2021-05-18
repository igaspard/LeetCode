class Solution {
   public:
    const vector<pair<int, int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        M = board.size();
        N = board[0].size();
        unordered_map<char, int> board_freq;
        for (int j = 0; j < M; ++j)
            for (int i = 0; i < N; ++i) ++board_freq[board[j][i]];

        vector<string> ans;
        for (auto word : words) {
            unordered_map<char, int> word_freq;
            for (auto ch : word) ++word_freq[ch];
            bool not_match = false;
            for (auto entry : word_freq) {
                if (board_freq.count(entry.first) == 0 || board_freq[entry.first] < entry.second) {
                    not_match = true;
                    break;
                }
            }
            if (not_match) continue;

            vector<vector<bool>> visited(M, vector<bool>(N, false));
            bool found = false;
            for (int j = 0; j < M; ++j) {
                for (int i = 0; i < N; ++i) {
                    found = dfs(board, j, i, visited, word, 0);
                    if (found) {
                        ans.emplace_back(word);
                        break;
                    }
                }
                if (found) break;
            }
        }

        return ans;
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
// Runtime: 56 ms, faster than 83.86% of C++ online submissions for Word Search II.
// Memory Usage: 9.1 MB, less than 77.89% of C++ online submissions for Word Search II.