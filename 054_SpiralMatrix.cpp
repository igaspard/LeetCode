class Solution {
   public:
    vector<vector<int>> directs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> ans;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        M = matrix.size();
        N = matrix[0].size();

        vector<vector<bool>> visited(M, vector<bool>(N, false));
        dfs(matrix, visited, 0, 0, 0);
        return ans;
    }

   private:
    int M, N;
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int y, int x, int idx) {
        visited[y][x] = true;
        ans.emplace_back(matrix[y][x]);
        if (ans.size() == M * N) return;

        int Y = y + directs[idx][0];
        int X = x + directs[idx][1];

        if (Y < 0 || Y >= M || X < 0 || X >= N || visited[Y][X]) {
            idx = (idx + 1) % 4;
            Y = y + directs[idx][0];
            X = x + directs[idx][1];
        }

        dfs(matrix, visited, Y, X, idx);
    }
};

// DFS time complexity: O(M*N), space complexity: O(M*N)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
// Memory Usage: 7.1 MB, less than 28.90% of C++ online submissions for Spiral Matrix.
