class Solution {
public:
    int dfs(int x, int y, vector< vector<int> > &matrix, vector< vector<int> > &dp) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (dp[x][y]) return dp[x][y];

        if (x!=0 && matrix[x-1][y] > matrix[x][y]) // left
            dp[x][y] = max(dp[x][y], dfs(x-1, y, matrix, dp));

        if (x!=m-1 && matrix[x+1][y] > matrix[x][y]) // right
            dp[x][y] = max(dp[x][y], dfs(x+1, y, matrix, dp));

        if (y!=0 && matrix[x][y-1] > matrix[x][y]) // up
            dp[x][y] = max(dp[x][y], dfs(x, y-1, matrix, dp));

        if (y!=n-1 && matrix[x][y+1] > matrix[x][y]) // down
            dp[x][y] = max(dp[x][y], dfs(x, y+1, matrix, dp));

        return ++dp[x][y];

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();

        vector< vector<int> > dp (m, vector<int>(n, 0));        
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, dfs(i, j , matrix, dp));
            }
        }
        return ans;
    }
};
