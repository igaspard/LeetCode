class Solution {
   public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        N = mat.size();
        if (isSameMatrix(mat, target)) return true;

        vector<vector<int>> rotated90 = rotate90(mat);
        if (isSameMatrix(rotated90, target)) return true;

        vector<vector<int>> rotated180 = rotate90(rotated90);
        if (isSameMatrix(rotated180, target)) return true;

        vector<vector<int>> rotated270 = rotate90(rotated180);
        if (isSameMatrix(rotated270, target)) return true;

        return false;
    }

   private:
    int N;

    bool isSameMatrix(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (mat[j][i] != target[j][i]) return false;

        return true;
    }

    vector<vector<int>> rotate90(vector<vector<int>>& mat) {
        // transpose
        vector<vector<int>> rotated(N, vector<int>(N));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) rotated[i][j] = mat[j][i];

        // reverse each row
        for (int j = 0; j < N; ++j) reverse(rotated[j].begin(), rotated[j].end());

        return rotated;
    }
};

// Runtime: 8 ms, faster than 20.00% of C++ online submissions for Determine Whether Matrix Can Be Obtained By
// Rotation. Memory Usage: 11.3 MB, less than 20.00% of C++ online submissions for Determine Whether Matrix
// Can Be Obtained By Rotation.