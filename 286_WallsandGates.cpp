class Solution {
   public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int GATE = 0, EMPTY = numeric_limits<int>::max(), WALL = -1;
        queue<pair<int, int>> q;
        for (int j = 0; j < rooms.size(); ++j) {
            for (int i = 0; i < rooms[0].size(); ++i) {
                if (!rooms[j][i]) q.push({j, i});
            }
        }

        vector<pair<int, int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int cur_y = cur.first;
            int cur_x = cur.second;

            for (auto direct : directs) {
                int y = cur_y + direct.first;
                int x = cur_x + direct.second;
                if (x < 0 || x >= rooms[0].size() || y < 0 || y >= rooms.size() || rooms[y][x] != EMPTY)
                    continue;
                rooms[y][x] = rooms[cur_y][cur_x] + 1;
                q.push({y, x});
            }
        }
    }
};

// BFS
// Runtime: 52 ms, faster than 98.12% of C++ online submissions for Walls and Gates.
// Memory Usage: 14.8 MB, less than 50.85% of C++ online submissions for Walls and Gates.

class Solution {
    vector<pair<int, int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for (int j = 0; j < rooms.size(); ++j) {
            for (int i = 0; i < rooms[0].size(); ++i) {
                if (rooms[j][i] == 0) dfs(rooms, j, i, 0);
            }
        }
    }

    void dfs(vector<vector<int>>& rooms, int y, int x, int distance) {
        if (x < 0 || x >= rooms[0].size() || y < 0 || y >= rooms.size() || rooms[y][x] < distance) return;

        rooms[y][x] = distance;

        for (auto direct : directs)
            dfs(rooms, y + direct.first, x + direct.second, distance + 1);
    }
};

// DFS
// Time complexity: O(M*N)
// Space complexity: O(1)
// Runtime: 56 ms, faster than 96.56% of C++ online submissions for Walls and Gates.
// Memory Usage: 14.2 MB, less than 93.02% of C++ online submissions for Walls and Gates.