class Solution {
public:
    int DFS(vector<vector<int>>& grid, int x, int y, int n) {

      if (x < 0 || x == grid[0].size() || 
          y < 0 || y == grid.size() ||
          grid[y][x] == -1) return 0;

      if (grid[y][x] == 2) return n == 0;

      grid[y][x] = -1;
      int paths = DFS(grid, x+1, y, n-1) +
                  DFS(grid, x, y+1, n-1) +
                  DFS(grid, x-1, y, n-1) +
                  DFS(grid, x, y-1, n-1);
      grid[y][x] = 0;
      return paths;

    }

    int uniquePathsIII(vector<vector<int>>& grid) {
      int sx = -1;
      int sy = -1;
      int n = 1;

      for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
          if (grid[i][j] == 0) ++n;
          else if (grid[i][j] == 1) {sx = j; sy = i;};

      return DFS(grid, sx, sy, n);  
    }
};

// Runtime: 4 ms, faster than 77.32% of C++ online submissions for Unique Paths III.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Unique Paths III.