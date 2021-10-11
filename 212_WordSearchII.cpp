class TrieNode {
   public:
    vector<TrieNode*> children;
    string word;

    TrieNode() : children(26), word("") {}
    ~TrieNode() {
        for (auto child : children) delete child;
    }
};

class Solution {
   public:
    const vector<pair<int, int>> directs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        M = board.size();
        N = board[0].size();

        TrieNode* root = new TrieNode();
        buildTrie(root, words);

        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                char ch = board[j][i] - 'a';
                if (root->children[ch] != nullptr) dfs(board, root, j, i);
            }
        }

        return ans;
    }

   private:
    int M, N;
    void buildTrie(TrieNode* root, vector<string> words) {
        for (auto word : words) {
            auto cur = root;
            for (auto ch : word) {
                ch -= 'a';
                if (cur->children[ch] == nullptr) cur->children[ch] = new TrieNode();
                cur = cur->children[ch];
            }
            cur->word = word;
        }
    }

    void dfs(vector<vector<char>>& board, TrieNode* cur, int y, int x) {
        if (y < 0 || y == M || x < 0 || x == N || board[y][x] == '*') return;

        char ch = board[y][x] - 'a';
        if (cur->children[ch] == nullptr) return;

        cur = cur->children[ch];
        if (!cur->word.empty()) {
            ans.emplace_back(cur->word);
            cur->word = "";
        }

        char backup = board[y][x];
        board[y][x] = '*';
        for (auto d : directs) dfs(board, cur, y + d.first, x + d.second);
        board[y][x] = backup;
    }
};

// DFS + backtracking + Trie
// Runtime: 356 ms, faster than 63.51% of C++ online submissions for Word Search II.
// Memory Usage: 9.8 MB, less than 22.93% of C++ online submissions for Word Search II.

class Solution {
   public:
    const vector<pair<int, int>> directs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        M = board.size();
        N = board[0].size();
        unordered_map<char, int> freq;
        for (int j = 0; j < M; ++j)
            for (int i = 0; i < N; ++i) ++freq[board[j][i]];

        vector<string> ans;
        for (auto w : words) {
            // check if this possible
            unordered_map<char, int> word_freq;
            for (auto ch : w) ++word_freq[ch];
            bool not_match = false;
            for (auto it : word_freq) {
                if (freq.count(it.first) == 0 || freq[it.first] < it.second) not_match = true;
            }
            if (not_match) continue;

            bool found = false;
            for (int j = 0; j < M; ++j) {
                for (int i = 0; i < N; ++i) {
                    if (board[j][i] == w[0]) {
                        if (dfs(board, j, i, 0, w)) {
                            ans.emplace_back(w);
                            found = true;
                            break;
                        }
                    }
                }
                if (found) break;
            }
        }

        return ans;
    }

   private:
    int M, N;
    bool dfs(vector<vector<char>>& board, int y, int x, int i, string str) {
        if (y < 0 || y >= M || x < 0 || x >= N || str[i] != board[y][x]) return false;
        if (i == str.length() - 1) return true;

        char backup = board[y][x];
        board[y][x] = '0';
        bool found = false;
        for (auto d : directs) found |= dfs(board, y + d.first, x + d.second, i + 1, str);

        board[y][x] = backup;

        return found;
    }
};

// DFS + backtracking + hash table to filter possible to find it out
// Runtime: 72 ms, faster than 88.08% of C++ online submissions for Word Search II.
// Memory Usage: 9.5 MB, less than 39.29% of C++ online submissions for Word Search II.

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