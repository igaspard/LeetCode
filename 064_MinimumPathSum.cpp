class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int M = grid.size();
        if (!M) return 0;
        const int N = grid[0].size();
        int dp[M][N];
        
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (!j && !i) dp[j][i] = grid[j][i];
                else if (!j) dp[j][i] = dp[j][i-1] + grid[j][i];
                else if (!i) dp[j][i] = dp[j-1][i] + grid[j][i];
                else dp[j][i] = min(dp[j][i-1], dp[j-1][i]) + grid[j][i];
            }
        }
        
        return dp[M-1][N-1];
    }
};


// DP 2D Counting
// Time complexity: O(mn)
// Time complexity: O(mn)
// Runtime: 8 ms, faster than 99.99% of C++ online submissions for Minimum Path Sum.
// Memory Usage: 10 MB, less than 8.97% of C++ online submissions for Minimum Path Sum.