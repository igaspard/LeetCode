class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int M = matrix.size();
        const int N = matrix[0].size();

        bool zero_rows = false, zero_cols = false;
        for (int i = 0; i < N; ++i) {
            if (matrix[0][i] == 0) {
                zero_rows = true;
                break;
            }
        }
        for (int j = 0; j < M; ++j) {
            if (matrix[j][0] == 0) {
                zero_cols = true;
                break;
            }
        }
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (matrix[j][i] == 0) {
                    matrix[j][0] = matrix[0][i] = 0;
                }
            }
        }

        for (int j = 1; j < M; ++j)
            for (int i = 1; i < N; ++i)
                if (matrix[j][0] == 0 || matrix[0][i] == 0) matrix[j][i] = 0;

        if (zero_rows) {
            for (int i = 0; i < N; ++i) matrix[0][i] = 0;
        }
        if (zero_cols) {
            for (int j = 0; j < M; ++j) matrix[j][0] = 0;
        }
    }
};

// use first row/col to recard if there is a element zero in that row/col
// time complexity: O(M*N), space complexity: O(1)
// Runtime: 8 ms, faster than 97.75% of C++ online submissions for Set Matrix Zeroes.
// Memory Usage: 13.2 MB, less than 53.91% of C++ online submissions for Set Matrix Zeroes.

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int M = matrix.size();
        const int N = matrix[0].size();

        unordered_set<int> rows, cols;
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (matrix[j][i] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (int j = 0; j < M; ++j)
            for (int i = 0; i < N; ++i)
                if (rows.count(i) || cols.count(j)) matrix[j][i] = 0;
    }
};

// time complexity: O(M*N), space complexity: O(M*N)
// Runtime: 12 ms, faster than 84.36% of C++ online submissions for Set Matrix Zeroes.
// Memory Usage: 13.4 MB, less than 19.70% of C++ online submissions for Set Matrix Zeroes.