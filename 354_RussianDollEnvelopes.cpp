class Solution {
   public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        // sort width increasing & height decreasing
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &A, const vector<int> &B) {
            if (A[0] == B[0])
                return A[1] > B[1];
            else
                return A[0] < B[0];
        });

        // find LIS in height
        const int N = envelopes.size();
        vector<int> top(N, 0);

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            int poker = envelopes[i][1];

            auto it = lower_bound(top.begin(), top.begin() + ans, poker);
            if (it == top.begin() + ans) ++ans;
            *it = poker;
        }

        return ans;
    }
};

// sort + binary search
// Runtime: 40 ms, faster than 89.62% of C++ online submissions for Russian Doll Envelopes.
// Memory Usage: 16.3 MB, less than 51.26% of C++ online submissions for Russian Doll Envelopes.

class Solution {
   public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        // sort width increasing & height decreasing
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &A, const vector<int> &B) {
            if (A[0] == B[0])
                return A[1] > B[1];
            else
                return A[0] < B[0];
        });

        // find LIS in height
        const int N = envelopes.size();
        vector<int> dp(N, 1);

        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][1] < envelopes[i][1]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

// sort + DP (LIS)
// Runtime: 876 ms, faster than 57.85% of C++ online submissions for Russian Doll Envelopes.
// Memory Usage: 16.3 MB, less than 51.26% of C++ online submissions for Russian Doll Envelopes.