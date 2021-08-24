class Solution {
   public:
    typedef pair<int, int> pii;
    const vector<pii> directs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;

        const int N = grid.size();
        queue<pii> q;
        q.emplace(0, 0);
        grid[0][0] = 1;  // visited

        int ans = 0;
        while (!q.empty()) {
            int size = q.size();

            ++ans;
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                if (cur.first == N - 1 && cur.second == N - 1) return ans;

                for (auto dir : directs) {
                    int y = cur.first + dir.first;
                    int x = cur.second + dir.second;

                    if (y < 0 || y >= N || x < 0 || x >= N || grid[y][x] == 1) continue;

                    q.emplace(y, x);
                    grid[y][x] = 1;
                }
            }
        }

        return -1;
    }
};

// BFS
// Runtime: 48 ms, faster than 93.87% of C++ online submissions for Shortest Path in Binary Matrix.
// Memory Usage: 19.2 MB, less than 93.03% of C++ online submissions for Shortest Path in Binary Matrix.
