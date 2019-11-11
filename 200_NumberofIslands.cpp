class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size())   return 0;

        int ans = 0;
        for(int j = 0; j < grid.size(); j++) {
            for (int i = 0; i < grid[0].size(); i++) {
                if (grid[j][i] == '1') {
                    ans++;
                    dfs(grid, j, i);
                }
            }
        }

        return ans;
    }
    
    void dfs(vector<vector<char>>& grid, int y, int x) {
        if ( x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[y][x] != '1')
            return;
                
        grid[y][x] = '*';
        dfs(grid, y-1, x);
        dfs(grid, y+1, x);
        dfs(grid, y, x-1);
        dfs(grid, y, x+1);        
    }
};

// Runtime: 16 ms, faster than 59.33% of C++ online submissions for Number of Islands.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Number of Islands.