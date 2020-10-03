class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ans = 0;
        for (int j = 0; j < grid.size(); ++j) {
            for (int i = 0; i < grid[0].size(); ++i) {
                if (grid[j][i] == '1') {
                    q.push({j, i});
                    grid[j][i] = '0';

                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();

                        for (auto direct : directs) {
                            const int y = cur.first + direct.first;
                            const int x = cur.second + direct.second;
                            if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() ||
                                grid[y][x] == '0')
                                continue;
                            grid[y][x] = '0';
                            q.push({y, x});
                        }
                    }
                    ++ans;
                }
            }
        }

        return ans;
    }
};

// BFS
// Runtime: 32 ms, faster than 50.24% of C++ online submissions for Number of Islands.
// Memory Usage: 10.3 MB, less than 21.51% of C++ online submissions for Number of Islands.

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size()) return 0;

        int ans = 0;
        for (int j = 0; j < grid.size(); j++) {
            for (int i = 0; i < grid[0].size(); i++) {
                if (grid[j][i] == '1') {
                    ans++;
                    dfs(grid, j, i);
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>>& grid, int y, int x) {
        if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[y][x] != '1') return;

        grid[y][x] = '*';
        dfs(grid, y - 1, x);
        dfs(grid, y + 1, x);
        dfs(grid, y, x - 1);
        dfs(grid, y, x + 1);
    }
};

// dfs
// Runtime: 16 ms, faster than 59.33% of C++ online submissions for Number of Islands.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Number of Islands.