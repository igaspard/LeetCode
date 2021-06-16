class Solution {
   public:
    const vector<pair<int, int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int swimInWater(vector<vector<int>>& grid) {
        N = grid.size();
        int left = grid[0][0], right = N * N;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            vector<vector<bool>> visited(N, vector<bool>(N, false));
            if (dfs(grid, 0, 0, mid, visited))
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }

   private:
    int N;

    bool dfs(vector<vector<int>>& grid, int y, int x, int t, vector<vector<bool>>& visited) {
        if (y < 0 || y >= N || x < 0 || x >= N || visited[y][x] || grid[y][x] > t) return false;

        visited[y][x] = true;
        if (y == N - 1 && x == N - 1) return true;

        bool canReach = false;
        for (auto d : directs) canReach |= dfs(grid, y + d.first, x + d.second, t, visited);

        return canReach;
    }
};

// binary search + DFS
// Runtime: 24 ms, faster than 49.95% of C++ online submissions for Swim in Rising Water.
// Memory Usage: 9.7 MB, less than 49.30% of C++ online submissions for Swim in Rising Water.

class Solution {
   public:
    const vector<pair<int, int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int swimInWater(vector<vector<int>>& grid) {
        N = grid.size();
        int left = grid[0][0], right = N * N;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (CanReach(grid, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }

   private:
    int N;

    bool CanReach(vector<vector<int>>& grid, int times) {
        unordered_set<int> visited;
        stack<int> s;
        s.push(0);
        visited.insert(0);

        int ans = 0;
        while (!s.empty()) {
            int k = s.top();
            s.pop();
            int y = k / N;
            int x = k % N;
            if (y == N - 1 && x == N - 1) return true;

            for (auto d : directs) {
                int Y = y + d.first;
                int X = x + d.second;
                int K = Y * N + X;
                if (Y >= 0 && Y < N && X >= 0 && X < N && !visited.count(K) && grid[Y][X] <= times) {
                    s.push(K);
                    visited.insert(K);
                }
            }
        }

        return false;
    }
};

// binary search + bfs
// Runtime: 60 ms, faster than 18.05% of C++ online submissions for Swim in Rising Water.
// Memory Usage: 19.2 MB, less than 7.86% of C++ online submissions for Swim in Rising Water.

class Solution {
   public:
    const vector<pair<int, int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int swimInWater(vector<vector<int>>& grid) {
        const int N = grid.size();
        unordered_set<int> visited;

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;
        minHeap.push({grid[0][0], 0, 0});
        visited.insert(grid[0][0]);

        int ans = 0;
        while (!minHeap.empty()) {
            auto [h, y, x] = minHeap.top();
            minHeap.pop();
            ans = max(ans, h);
            if (y == N - 1 && x == N - 1) return ans;

            for (auto dir : directs) {
                int Y = y + dir.first;
                int X = x + dir.second;
                if (Y >= 0 && Y < N && X >= 0 && X < N && !visited.count(grid[Y][X])) {
                    minHeap.push({grid[Y][X], Y, X});
                    visited.insert(grid[Y][X]);
                }
            }
        }

        return ans;
    }
};

// BFS Heap
// time complexity: O(N^2 * logN), N^2 nodes * O(logN) heap operations
// Runtime: 24 ms, faster than 49.95% of C++ online submissions for Swim in Rising Water.
// Memory Usage: 10.6 MB, less than 40.79% of C++ online submissions for Swim in Rising Water.
