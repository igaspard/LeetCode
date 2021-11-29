class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        
        reverse(matrix.begin(), matrix.end());
        for (int j = 0; j < N; ++j) 
            for (int i = j + 1; i < N; ++i)
                swap(matrix[i][j], matrix[j][i]);
    }
};

/*
reverse rows, then swap symmetry

1 2 3       7 8 9       7 4 1
4 5 6 ->    4 5 6 ->    8 5 2
7 8 9       1 2 3       9 6 3
*/
// Runtime: 4 ms, faster than 55.12% of C++ online submissions for Rotate Image.
// Memory Usage: 7.2 MB, less than 31.65% of C++ online submissions for Rotate Image.
