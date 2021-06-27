class Solution {
   public:
    int twoEggDrop(int n) {
        const int K = 2;
        int dp[K + 1][n + 1];

        for (int j = 0; j <= K; ++j)
            for (int i = 0; i <= n; ++i) dp[j][i] = 0;

        int m = 0;
        while (dp[K][m] < n) {
            ++m;
            for (int k = 1; k <= K; ++k) dp[k][m] = dp[k - 1][m - 1] + dp[k][m - 1] + 1;
        }

        return m;
    }
};

// dp, same #887
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Egg Drop With 2 Eggs and N Floors.
// Memory Usage: 6 MB, less than 61.18% of C++ online submissions for Egg Drop With 2 Eggs and N Floors.