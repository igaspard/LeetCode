class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int M = text1.length();
        const int N = text2.length();
        
        vector<vector<int>> LCS(N+1, vector<int>(M+1, 0));
        
        int ans = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j<=M; ++j) {
                if (text1[j-1] == text2[i-1])
                    LCS[i][j] = 1 + LCS[i-1][j-1];
                else
                    LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
                ans = max(ans, LCS[i][j]);
             }
        }
        return ans;
    }
};

// DP
// Time complexity: O(M*N)
// Space complexity: O(M*N)
// Runtime: 28 ms, faster than 55.54% of C++ online submissions for Longest Common Subsequence.
// Memory Usage: 13 MB, less than 14.77% of C++ online submissions for Longest Common Subsequence.