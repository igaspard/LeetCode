class Solution {
   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        M = matrix.size();
        N = matrix[0].size();

        vector<vector<int>> dp(M, vector<int>(N, 0));
        int ans = 1;
        for (int j = 0; j < M; ++j)
            for (int i = 0; i < N; ++i) ans = max(ans, dfs(matrix, j, i, INT_MIN));

        return ans;
    }

   private:
    int M, N;
    const vector<vector<int>> directs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int y, int x, int pre) {
        if (y < 0 || y >= M || x < 0 || x >= N || pre >= matrix[y][x]) return 0;

        if (dp[y][x]) return dp[y][x];

        int ans = 1;
        for (auto d : directs) ans = max(ans, dfs(matrix, dp, y + d[0], x + d[1], matrix[y][x]) + 1);

        return dp[y][x] = ans;
    }
};

// dfs with memories
// Runtime: 168 ms, faster than 15.87% of C++ online submissions for Longest Increasing Path in a Matrix.
// Memory Usage: 40.9 MB, less than 11.96% of C++ online submissions for Longest Increasing Path in a Matrix.

class Solution {
   public:
    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (dp[x][y]) return dp[x][y];

        if (x != 0 && matrix[x - 1][y] > matrix[x][y])  // left
            dp[x][y] = max(dp[x][y], dfs(x - 1, y, matrix, dp));

        if (x != m - 1 && matrix[x + 1][y] > matrix[x][y])  // right
            dp[x][y] = max(dp[x][y], dfs(x + 1, y, matrix, dp));

        if (y != 0 && matrix[x][y - 1] > matrix[x][y])  // up
            dp[x][y] = max(dp[x][y], dfs(x, y - 1, matrix, dp));

        if (y != n - 1 && matrix[x][y + 1] > matrix[x][y])  // down
            dp[x][y] = max(dp[x][y], dfs(x, y + 1, matrix, dp));

        return ++dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }
        return ans;
    }
};
