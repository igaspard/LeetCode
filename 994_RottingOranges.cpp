class Solution {
   public:
    const int FRESH = 1, EMPTY = 0, ROTTEN = 2;
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int j = 0; j < grid.size(); ++j) {
            for (int i = 0; i < grid[0].size(); ++i) {
                if (grid[j][i] == ROTTEN) {
                    q.push({j, i});
                } else if (grid[j][i] == FRESH) {
                    ++fresh;
                }
            }
        }

        if (fresh == 0) return 0;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ans = -1;
        while (!q.empty()) {
            const int len = q.size();
            for (int i = 0; i < len; ++i) {
                auto cur = q.front();
                q.pop();
                for (auto direct : directions) {
                    int y = cur.first + direct.first;
                    int x = cur.second + direct.second;
                    if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[y][x] != FRESH)
                        continue;
                    grid[y][x] = 2;
                    --fresh;
                    q.push({y, x});
                }
            }
            ++ans;
        }

        return !fresh ? ans : -1;
    }
};

// BFS, finding 
// Runtime: 12 ms, faster than 65.93% of C++ online submissions for Rotting Oranges.
// Memory Usage: 13.5 MB, less than 27.80% of C++ online submissions for Rotting Oranges.