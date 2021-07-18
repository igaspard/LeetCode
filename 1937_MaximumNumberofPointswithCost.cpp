class Solution {
   public:
    long long maxPoints(vector<vector<int>>& points) {
        const int M = points.size();
        const int N = points[0].size();

        long long dp[M][N];
        for (int i = 0; i < N; ++i) dp[0][i] = points[0][i];
        for (int j = 1; j < M; ++j)
            for (int i = 0; i < N; ++i) dp[j][i] = -1;

        for (int j = 1; j < M; ++j) {
            vector<long long> left(N, -1);
            vector<long long> right(N, -1);

            left[0] = dp[j - 1][0];
            for (int k = 1; k < N; ++k) left[k] = max(left[k - 1], dp[j - 1][k] + k);

            right[N - 1] = dp[j - 1][N - 1] - N + 1;
            for (int k = N - 2; k >= 0; --k) right[k] = max(right[k + 1], dp[j - 1][k] - k);

            for (int i = 0; i < N; ++i) dp[j][i] = max(left[i] - i, right[i] + i) + points[j][i];
        }

        long long ans = 0;
        for (int i = 0; i < N; ++i) ans = max(ans, dp[M - 1][i]);

        return ans;
    }
};

// DP
// dp[j][i] define as max of points[j][i]
// dp[j][i] max(dp[j-1][k] - abs(i-k) + points[j][i]) 0 <= k <= N -1
//  Left abs(i-k) -> i - k : max(dp[j-1][k] + k) - j + points[j][i]
// right abs(i-k) -> k - i : max(dp[j-1][k] - k) + j + points[j][i]
//                dp[j][i] = max(left[i] - i, right[i] + i) + points[j][i]
// Runtime: 308 ms, faster than 100.00% of C++ online submissions for Maximum Number of Points with Cost.
// Memory Usage: 110.7 MB, less than 50.00% of C++ online submissions for Maximum Number of Points with Cost.