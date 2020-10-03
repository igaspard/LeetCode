class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;

        for (int j = 0; j < grid.size(); ++j) {
            for (int i = 0; i < grid[0].size(); ++i) {
                if (grid[j][i] == 1) {
                    int path = dfs(grid, j, i);
                    ans = max(ans, path);
                }
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int y, int x) {
        if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[y][x] != 1) return 0;

        grid[y][x] = 0;
        return 1 + dfs(grid, y - 1, x) + dfs(grid, y + 1, x) + dfs(grid, y, x - 1) + dfs(grid, y, x + 1);
    }
};

// DFS
// Runtime: 24 ms, faster than 97.11% of C++ online submissions for Max Area of Island.
// Memory Usage: 23.3 MB, less than 72.15% of C++ online submissions for Max Area of Island.