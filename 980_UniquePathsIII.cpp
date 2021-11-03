class Solution {
   public:
    int ans;
    int uniquePathsIII(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();

        ans = 0, empty = 1;
        int start_y, start_x;
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (grid[j][i] == 0) {
                    ++empty;
                } else if (grid[j][i] == 1) {
                    start_y = j;
                    start_x = i;
                }
            }
        }

        backtracing(grid, start_y, start_x, 0);

        return ans;
    }

   private:
    int M, N, empty;
    const vector<pair<int, int>> directs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void backtracing(vector<vector<int>>& grid, int y, int x, int cnt) {
        if (y < 0 || y >= M || x < 0 || x >= N || grid[y][x] == -1) return;

        if (grid[y][x] == 2) {
            if (cnt == empty) ++ans;
            return;
        }

        grid[y][x] = -1;
        for (auto d : directs) backtracing(grid, y + d.first, x + d.second, cnt + 1);
        grid[y][x] = 0;
    }
};

// dfs with backtracking
// Runtime: 4 ms, faster than 74.46% of C++ online submissions for Unique Paths III.
// Memory Usage: 7 MB, less than 67.27% of C++ online submissions for Unique Paths III.


class Solution {
   public:
    int DFS(vector<vector<int>>& grid, int x, int y, int n) {
        if (x < 0 || x == grid[0].size() || y < 0 || y == grid.size() || grid[y][x] == -1) return 0;

        if (grid[y][x] == 2) return n == 0;

        grid[y][x] = -1;
        int paths = DFS(grid, x + 1, y, n - 1) + DFS(grid, x, y + 1, n - 1) + DFS(grid, x - 1, y, n - 1) +
                    DFS(grid, x, y - 1, n - 1);
        grid[y][x] = 0;
        return paths;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx = -1;
        int sy = -1;
        int n = 1;

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 0)
                    ++n;
                else if (grid[i][j] == 1) {
                    sx = j;
                    sy = i;
                };

        return DFS(grid, sx, sy, n);
    }
};

// Runtime: 4 ms, faster than 77.32% of C++ online submissions for Unique Paths III.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Unique Paths III.