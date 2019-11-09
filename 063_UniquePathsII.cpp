class Solution {
public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // if there is obstacle in the frist cell, we can't move anyway.
        if (obstacleGrid[0][0]==1)
            return 0;
        
        long ans[m][n];
        ans[0][0] = 1;
        
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i]==1)
                ans[0][i] = 0;
            else
                ans[0][i] = ans[0][i-1];
        }
        
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0]==1)
                ans[i][0] = 0;
            else
                ans[i][0] = ans[i-1][0];
        }
            
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j]==1)
                    ans[i][j] = 0;
                else
                    ans[i][j] = ans[i-1][j] + ans[i][j-1];
            }
        }
            
        return ans[m-1][n-1];
    }
};

// Runtime: 4 ms, faster than 74.39% of C++ online submissions for Unique Paths II.
// Memory Usage: 9.2 MB, less than 93.33% of C++ online submissions for Unique Paths II.