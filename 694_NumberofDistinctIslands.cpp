class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set< vector<pair<int, int>> > ans;
        for(int j = 0; j < grid.size(); ++j) {
            for(int i = 0; i < grid[0].size(); ++i) {
                if(grid[j][i]==1) {
                    vector<pair<int, int>> islands;
                    dfs(grid, j, i, j, i, islands);
                    if (!islands.empty()) 
                        ans.insert(islands);
                }
            }
        }
        
        return ans.size();
    }
    
    void dfs(vector<vector<int>> &grid, int y, int x, int anchor_y, int anchor_x, vector<pair<int, int>> &island) {
        if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[y][x] != 1)
            return;

        island.push_back({y-anchor_y, x-anchor_x});
        grid[y][x] = -1;
        
        dfs(grid, y-1, x, anchor_y, anchor_x, island);
        dfs(grid, y+1, x, anchor_y, anchor_x, island);
        dfs(grid, y, x-1, anchor_y, anchor_x, island);
        dfs(grid, y, x+1, anchor_y, anchor_x, island);
    }
};

// DFS, use sequence of coordinates as island's shape
// Runtime: 68 ms, faster than 79.06% of C++ online submissions for Number of Distinct Islands.
// Memory Usage: 33.8 MB, less than 36.61% of C++ online submissions for Number of Distinct Islands.