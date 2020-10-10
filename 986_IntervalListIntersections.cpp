class Solution {
   public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0;
        vector<vector<int>> ans;

        while (i < A.size() && j < B.size()) {
            const int s = max(A[i][0], B[j][0]);
            const int e = min(A[i][1], B[j][1]);

            if (s <= e) ans.push_back({s, e});

            if (A[i][1] < B[j][1])
                i++;
            else
                j++;
        }

        return ans;
    }
};

// Intervals
// Runtime: 56 ms, faster than 94.42% of C++ online submissions for Interval List Intersections.
// Memory Usage: 18.9 MB, less than 11.23% of C++ online submissions for Interval List Intersections.