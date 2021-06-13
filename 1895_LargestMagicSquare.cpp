class Solution {
   public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        K = min(M, N);

        vector<vector<int>> preSumRow(M, vector<int>(N + 1, 0));
        vector<vector<int>> preSumCol(M + 1, vector<int>(N, 0));

        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (i == 0) {
                    preSumRow[j][i + 1] = grid[j][i];
                } else {
                    preSumRow[j][i + 1] = grid[j][i] + preSumRow[j][i];
                }

                if (j == 0) {
                    preSumCol[j + 1][i] = grid[j][i];
                } else {
                    preSumCol[j + 1][i] = grid[j][i] + preSumCol[j][i];
                }
            }
        }

        int ans = 1;
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                for (int k = 2; k <= K; ++k) {
                    bool isSquare = isSquareSum(grid, j, i, k, preSumRow, preSumCol);
                    if (isSquare) ans = max(ans, k);
                }
            }
        }

        return ans;
    }

   private:
    int M;
    int N;
    int K;

    bool isSquareSum(vector<vector<int>>& grid, int j, int i, int k, vector<vector<int>>& preSumRow,
                     vector<vector<int>>& preSumCol) {
        if (j + k > M || i + k > N) return false;

        int target = preSumRow[j][i + k] - preSumRow[j][i];

        // check row j + 1 ~ j + k
        for (int n = 1; n < k; ++n) {
            int sum = preSumRow[j + n][i + k] - preSumRow[j + n][i];
            if (sum != target) return false;
        }
        // check col i ~ i + k
        for (int n = 0; n < k; ++n) {
            int sum = preSumCol[j + k][i + n] - preSumCol[j][i + n];
            if (sum != target) return false;
        }
        // check Diagonal
        int diag_sum = 0;
        for (int n = 0; n < k; ++n) diag_sum += grid[j + n][i + n];
        if (diag_sum != target) return false;

        int rev_diag_sum = 0;
        for (int n = 0; n < k; ++n) rev_diag_sum += grid[j + n][i + k - 1 - n];
        if (rev_diag_sum != target) return false;

        return true;
    }
};

// prefix sum
// Runtime: 96 ms, faster than 58.33% of C++ online submissions for Largest Magic Square.
// Memory Usage: 10.1 MB, less than 100.00% of C++ online submissions for Largest Magic Square.