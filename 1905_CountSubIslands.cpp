class Solution {
   public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        M = grid1.size();
        N = grid1[0].size();

        int ans = 0;
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (grid2[j][i]) ans += dfs(grid1, grid2, j, i);
            }
        }

        return ans;
    }

   private:
    const vector<pair<int, int>> directs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int M, N;

    int dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int y, int x) {
        if (y < 0 || y >= M || x < 0 || x >= N || grid2[y][x] == 0) return 1;

        grid2[y][x] = 0;

        int ans = 1;
        for (auto d : directs) ans &= dfs(grid1, grid2, y + d.first, x + d.second);

        return ans & grid1[y][x];
    }
};

// dfs
// Runtime: 256 ms, faster than 80.00% of C++ online submissions for Count Sub Islands.
// Memory Usage: 102.2 MB, less than 60.00% of C++ online submissions for Count Sub Islands.