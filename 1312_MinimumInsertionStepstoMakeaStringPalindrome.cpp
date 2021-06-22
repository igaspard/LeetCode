class Solution {
   public:
    int minInsertions(string s) {
        const int N = s.length();

        int dp[N];
        for (int i = 0; i < N; ++i) dp[i] = 0;

        for (int i = N - 2; i >= 0; --i) {
            int pre = 0;
            for (int j = i + 1; j < N; ++j) {
                int temp = dp[j];
                if (s[i] == s[j])
                    dp[j] = pre;
                else
                    dp[j] = min(dp[j], dp[j - 1]) + 1;
                pre = temp;
            }
        }

        return dp[N - 1];
    }
};

// dp 2D compression to 1D
// Runtime: 12 ms, faster than 99.64% of C++ online submissions for Minimum Insertion Steps to Make a String
// Palindrome. Memory Usage: 6.3 MB, less than 99.64% of C++ online submissions for Minimum Insertion Steps to
// Make a String Palindrome.

class Solution {
   public:
    int minInsertions(string s) {
        const int N = s.length();

        int dp[N][N];
        for (int i = 0; i < N; ++i) {
            dp[i][i] = 0;
            if (i != 0) dp[i][i - 1] = 0;
        }

        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
                else
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }

        return dp[0][N - 1];
    }
};

// dp 2D defina dp[i][j] as s[i..j] min insertions
// Runtime: 12 ms, faster than 99.64% of C++ online submissions for Minimum Insertion Steps to Make a String
// Palindrome. Memory Usage: 7.5 MB, less than 55.67% of C++ online submissions for Minimum Insertion Steps to
// Make a String Palindrome.