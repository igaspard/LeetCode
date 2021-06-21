class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int M = text1.length();
        const int N = text2.length();
        
        int dp[M+1][N+1];
        for (int j = 0; j <= M; ++j) {
            for (int i = 0; i <= N; ++i) {
                if (i == 0 || j == 0) dp[j][i] = 0;
                else if (text1[j-1] == text2[i-1]) dp[j][i] = dp[j-1][i-1] + 1;
                else dp[j][i] = max(dp[j-1][i], dp[j][i-1]);
            }
        }
        
        return dp[M][N];
    }
};

// DP, use 2D array instead of vector
// Time complexity: O(M*N)
// Space complexity: O(M*N)
// Runtime: 8 ms, faster than 93.76% of C++ online submissions for Longest Common Subsequence.
// Memory Usage: 10.7 MB, less than 48.95% of C++ online submissions for Longest Common Subsequence.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int M = text1.length();
        const int N = text2.length();
        
        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
        for (int j = 1; j <= M; ++j) {
            for (int i = 1; i <= N; ++i) {
                if (text1[j-1] == text2[i-1]) dp[j][i] = dp[j-1][i-1] + 1;
                else dp[j][i] = max(dp[j-1][i], dp[j][i-1]);
            }
        }
        
        return dp[M][N];
    }
};

// DP
// Time complexity: O(M*N)
// Space complexity: O(M*N)
// Runtime: 20 ms, faster than 54.16% of C++ online submissions for Longest Common Subsequence.
// Memory Usage: 13 MB, less than 22.65% of C++ online submissions for Longest Common Subsequence.