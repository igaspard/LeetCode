class Solution {
   public:
    int closedIsland(vector<vector<int>> &grid) {
        if (grid.empty() || !grid[0].size()) return 0;
        const int M = grid.size();
        const int N = grid[0].size();

        int ans = 0;
        for (int j = 1; j < M - 1; ++j) {
            for (int i = 1; i < N - 1; ++i) {
                if (grid[j][i] == 0) {
                    bool internal_lake = true;
                    dfs(grid, j, i, internal_lake);
                    if (internal_lake) ++ans;
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>> &grid, int y, int x, bool &internal_lake) {
        if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size() || grid[y][x] != 0) return;

        grid[y][x] = -1;  // mark as Inland lake
        if (!y || !x || y == grid.size() - 1 || x == grid[0].size() - 1) internal_lake = false;

        vector<pair<int, int>> directs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto direct : directs) dfs(grid, y + direct.first, x + direct.second, internal_lake);
    }
};

// DFS
// Time complexity: O(m*n)
// Runtime: 36 ms, faster than 25.60% of C++ online submissions for Number of Closed Islands.
// Memory Usage: 11.6 MB, less than 5.29% of C++ online submissions for Number of Closed Islands.