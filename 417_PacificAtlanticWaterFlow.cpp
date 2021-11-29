class Solution {
   public:
    const vector<vector<int>> directs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        M = heights.size();
        N = heights[0].size();

        vector<vector<bool>> pacific(M, vector<bool>(N, false));
        vector<vector<bool>> atlantic(M, vector<bool>(N, false));
        for (int j = 0; j < M; ++j) {
            dfs(heights, INT_MIN, j, 0, pacific);
            dfs(heights, INT_MIN, j, N - 1, atlantic);
        }
        for (int i = 0; i < N; ++i) {
            dfs(heights, INT_MIN, 0, i, pacific);
            dfs(heights, INT_MIN, M - 1, i, atlantic);
        }

        vector<vector<int>> ans;
        for (int j = 0; j < M; ++j)
            for (int i = 0; i < N; ++i)
                if (pacific[j][i] && atlantic[j][i]) ans.push_back({j, i});

        return ans;
    }

   private:
    int M, N;
    void dfs(vector<vector<int>>& g, int h, int y, int x, vector<vector<bool>>& visited) {
        if (y < 0 || y >= M || x < 0 || x >= N || visited[y][x] || g[y][x] < h) return;

        visited[y][x] = true;
        for (auto d : directs) dfs(g, g[y][x], y + d[0], x + d[1], visited);
    }
};

// DFS from boarder
// Runtime: 72 ms, faster than 31.24% of C++ online submissions for Pacific Atlantic Water Flow.
// Memory Usage: 24.9 MB, less than 19.57% of C++ online submissions for Pacific Atlantic Water Flow.

class Solution {
   public:
    const vector<vector<int>> directs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        M = heights.size();
        N = heights[0].size();

        vector<vector<bool>> pacific(M, vector<bool>(N, false));
        vector<vector<bool>> atlantic(M, vector<bool>(N, false));
        queue<vector<int>> pq, aq;
        for (int j = 0; j < M; ++j) {
            pq.push({j, 0});
            aq.push({j, N - 1});
            pacific[j][0] = true;
            atlantic[j][N - 1] = true;
        }
        for (int i = 0; i < N; ++i) {
            pq.push({0, i});
            aq.push({M - 1, i});
            pacific[0][i] = true;
            atlantic[M - 1][i] = true;
        }
        bfs(heights, pq, pacific);
        bfs(heights, aq, atlantic);

        vector<vector<int>> ans;
        for (int j = 0; j < M; ++j)
            for (int i = 0; i < N; ++i)
                if (pacific[j][i] && atlantic[j][i]) ans.push_back({j, i});

        return ans;
    }

   private:
    int M, N;
    void bfs(vector<vector<int>>& g, queue<vector<int>>& q, vector<vector<bool>>& visited) {
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (auto d : directs) {
                int y = cur[0] + d[0];
                int x = cur[1] + d[1];
                if (y < 0 || y >= M || x < 0 || x >= N || visited[y][x] || g[y][x] < g[cur[0]][cur[1]])
                    continue;
                visited[y][x] = true;
                q.push({y, x});
            }
        }
    }
};

// BFS from boarder
// Runtime: 88 ms, faster than 22.66% of C++ online submissions for Pacific Atlantic Water Flow.
// Memory Usage: 29.3 MB, less than 13.19% of C++ online submissions for Pacific Atlantic Water Flow.

class Solution {
   public:
    const vector<vector<int>> directs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        M = heights.size();
        N = heights[0].size();

        vector<vector<int>> ans;
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (bfs(heights, j, i)) ans.push_back({j, i});
            }
        }

        return ans;
    }

   private:
    int M, N;
    bool bfs(vector<vector<int>>& g, int y, int x) {
        queue<vector<int>> q;
        q.push({y, x});

        bool bPacific = false, bAtlantic = false;
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (auto d : directs) {
                int Y = cur[0] + d[0];
                int X = cur[1] + d[1];
                if (Y < 0 || X < 0) {
                    bPacific = true;
                } else if (Y >= M || X >= N) {
                    bAtlantic = true;
                } else if (!visited[Y][X] && g[Y][X] <= g[cur[0]][cur[1]]) {
                    visited[Y][X] = true;
                    q.push({Y, X});
                }
                if (bPacific && bAtlantic) return true;
            }
        }

        return bPacific && bAtlantic;
    }
};

// TLE
// BFS every node