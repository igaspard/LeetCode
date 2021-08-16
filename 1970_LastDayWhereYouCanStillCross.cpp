class Solution {
   public:
    vector<pair<int, int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
        M = row;
        N = col;
        vector<vector<int>> island(M, vector<int>(N, 0));

        int left = 0, right = cells.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            for (int i = 0; i <= mid; ++i) island[cells[i][0] - 1][cells[i][1] - 1] = 1;

            bool canReached = canReachBFS(island);

            for (int i = 0; i <= mid; ++i) island[cells[i][0] - 1][cells[i][1] - 1] = 0;
            if (canReached)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return right + 1;
    }

   private:
    int M, N;
    bool canReachBFS(vector<vector<int>> &island) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        for (int i = 0; i < N; i++) {
            if (island[0][i] == 0) {
                visited[0][i] = true;
                q.push({0, i});
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                if (cur.first == M - 1) return true;
                for (auto dir : directs) {
                    int Y = cur.first + dir.first;
                    int X = cur.second + dir.second;
                    if (Y < 0 || Y >= M || X < 0 || X >= N || island[Y][X] == 1 || visited[Y][X]) continue;
                    visited[Y][X] = true;
                    q.push({Y, X});
                }
            }
        }

        return false;
    }
};

// BFS + binary search
// Runtime: 680 ms, faster than 40.00% of C++ online submissions for Last Day Where You Can Still Cross.
// Memory Usage: 184.8 MB, less than 40.00% of C++ online submissions for Last Day Where You Can Still Cross.

class Solution {
   public:
    vector<pair<int, int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
        M = row;
        N = col;
        vector<vector<int>> island(M, vector<int>(N, 0));

        int left = 0, right = cells.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            for (int i = 0; i <= mid; ++i) island[cells[i][0] - 1][cells[i][1] - 1] = 1;

            bool found = false;
            vector<vector<bool>> visited(M, vector<bool>(N, false));
            for (int i = 0; i < col; i++) {
                if (island[0][i] == 0) found = dfs(island, visited, 0, i);
                if (found) break;
            }

            for (int i = 0; i <= mid; ++i) island[cells[i][0] - 1][cells[i][1] - 1] = 0;
            if (found)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return right + 1;
    }

   private:
    int M, N;
    bool dfs(vector<vector<int>> &island, vector<vector<bool>> &visited, int y, int x) {
        if (y < 0 || y >= M || x < 0 || x >= N || island[y][x] == 1 || visited[y][x]) return false;

        visited[y][x] = true;

        if (y == M - 1) return true;

        for (auto dir : directs)
            if (dfs(island, visited, y + dir.first, x + dir.second)) return true;

        return false;
    }
};

// DFS + binary search
// Runtime: 532 ms, faster than 100.00% of C++ online submissions for Last Day Where You Can Still Cross.
// Memory Usage: 170.2 MB, less than 40.00% of C++ online submissions for Last Day Where You Can Still Cross.
