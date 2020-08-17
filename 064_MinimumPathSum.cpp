class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int ans[m][n];
        
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (!y && !x) 
                    ans[y][x] = grid[y][x];
                else if (!y) 
                    ans[y][x] = grid[y][x] + ans[y][x - 1];
                else if (!x)
                    ans[y][x] = grid[y][x] + ans[y - 1][x];
                else
                    ans[y][x] = grid[y][x] + min(ans[y][x - 1], ans[y - 1][x]);
            }
        }
        
        return ans[m - 1][n - 1];
    }
};

// Runtime: 16 ms, faster than 95.82% of C++ online submissions for Minimum Path Sum.
// Memory Usage: 10.1 MB, less than 43.42% of C++ online submissions for Minimum Path Sum.