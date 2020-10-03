class Solution {
public:
    const vector<pair<int, int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        vector<int> ans;
        for (auto pos: positions) {
            grid[pos[0]][pos[1]] = 1;
            ans.emplace_back(numIsland(grid));
        }
        
        return ans;
    }
    
    int numIsland(vector<vector<int>> grid) {
        int nums = 0;
        for (int j = 0; j < grid.size(); ++j) {
            for (int i = 0; i < grid[0].size(); ++i) {
                if (grid[j][i]==1) {
                    dfs(grid, j, i);
                    ++nums;
                }
            }
        }
        
        return nums;
    }
    
    void dfs(vector<vector<int>> &grid, int y, int x) {
        if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[y][x] != 1) 
            return;
        
        grid[y][x] = 0;
        for (auto direct: directs) 
            dfs(grid, y+direct.first, x+direct.second);
    }
};

// DFS algorithm, Time Limit Exceeded
