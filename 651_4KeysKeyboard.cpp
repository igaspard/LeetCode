class Solution {
   public:
    int maxA(int n) {
        int dp[n + 1];

        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1; // last move is press A
            // A, A, A ...... Ctrl+A, Ctrl+C, Ctrl+V, Ctrl+V, ... Ctrl+V,
            for (int j = 2; j < i; ++j) // find out from idx j to press Ctrl+V, first 2 moves are Ctrl+A, Ctrl+C
                dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
        }

        return dp[n];
    }
};

// DP define dp[i] as when max A num when there are n remain moves
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for 4 Keys Keyboard.
// Memory Usage: 5.9 MB, less than 83.70% of C++ online submissions for 4 Keys Keyboard.

class Solution {
   public:
    int maxA(int n) { return dp(n, 0, 0); }

    int dp(int n, int a_num, int copy) {
        if (n <= 0) return a_num;

        return max(dp(n - 1, a_num + 1, copy), max(dp(n - 1, a_num + copy, copy), dp(n - 2, a_num, a_num)));
    }
};

// TLE