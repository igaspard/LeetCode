class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        const int N = s.length();

        int dp[N][N];
        for (int i = 0; i < N; ++i) {  // base cases
            dp[i][i] = 1;
            if (i != 0) dp[i][i - 1] = 0;
        }

        for (int i = N - 1; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }

        return dp[0][N - 1];
    }
};

// dp, 2D, define dp[i][j] as s[i..j] LPS(Longest Palindrome Subseq)
// Runtime: 32 ms, faster than 99.06% of C++ online submissions for Longest Palindromic Subsequence.
// Memory Usage: 10.7 MB, less than 83.98% of C++ online submissions for Longest Palindromic Subsequence.