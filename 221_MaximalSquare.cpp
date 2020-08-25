class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {        
        if (!matrix.size() || !matrix[0].size()) return 0; // matrix[0] might be empty
        const int M = matrix.size();
        const int N = matrix[0].size();
        
        vector<vector<int>> dp(M, vector<int>(N, 0));
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!i || !j)
                    dp[i][j] = matrix[i][j] - '0';
                else if (matrix[i][j] == '1')
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};

// DP
// dp(i,j) = min(dp(i−1,j), dp(i−1,j−1), dp(i,j−1)) + 1
// Time complexity: O(mn)
// Space complexity: O(mn)
// Runtime: 92 ms, faster than 11.78% of C++ online submissions for Maximal Square.
// Memory Usage: 11.6 MB, less than 48.04% of C++ online submissions for Maximal Square.