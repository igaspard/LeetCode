class Solution {
   public:
    int minDistance(string word1, string word2) {
        const int M = word1.length();
        const int N = word2.length();
        // define dp(i, j) return s1[0..i-1], s2[0..j-1] min edit distance
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        // base cases
        for (int i = 1; i <= M; ++i) dp[i][0] = i;
        for (int j = 1; j <= N; ++j) dp[0][j] = j;

        // state change, bottom up
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1));
            }
        }

        return dp[M][N];
    }
};

// dp bottom up
// Runtime: 16 ms, faster than 45.50% of C++ online submissions for Edit Distance.
// Memory Usage: 8.9 MB, less than 51.08% of C++ online submissions for Edit Distance.

class Solution {
   public:
    const int INIT_VALUE = -666;
    int minDistance(string word1, string word2) {
        const int M = word1.length();
        const int N = word2.length();

        vector<vector<int>> memo(M + 1, vector<int>(N + 1, INIT_VALUE));
        return dp(memo, word1, word2, M - 1, N - 1);
    }

    int dp(vector<vector<int>> &memo, string s1, string s2, int i, int j) {
        if (i == -1) return j + 1;
        if (j == -1) return i + 1;
        if (memo[i][j] != INIT_VALUE) return memo[i][j];

        if (s1[i] == s2[j])
            memo[i][j] = dp(memo, s1, s2, i - 1, j - 1);
        else {
            memo[i][j] = min(dp(memo, s1, s2, i, j - 1) + 1,
                             min(dp(memo, s1, s2, i - 1, j) + 1, dp(memo, s1, s2, i - 1, j - 1) + 1));
        }

        return memo[i][j];
    }
};

// recursive w/ memo top down
// Runtime: 40 ms, faster than 19.69% of C++ online submissions for Edit Distance.
// Memory Usage: 80.8 MB, less than 6.56% of C++ online submissions for Edit Distance.

class Solution {
   public:
    int minDistance(string word1, string word2) {
        return dp(word1, word2, word1.length() - 1, word2.length() - 1);
    }
    // define dp(i, j) return s1[0..i], s2[0..j] min edit distance
    int dp(string s1, string s2, int i, int j) {
        // base cases
        if (i == -1) return j + 1;  // when s1 reach to -1, s2 need to insert from j to 0 chars
        if (j == -1) return i + 1;  // when s2 reach to -1, s1 need to delete from i to 0 chars

        // state change
        if (s1[i] == s2[j])
            return dp(s1, s2, i - 1, j - 1);  // same, do nothing move on next char
        else {
            return min(dp(s1, s2, i, j - 1) + 1,            // insert
                       min(dp(s1, s2, i - 1, j) + 1,        // delete
                           dp(s1, s2, i - 1, j - 1) + 1));  // replace
        }
    }
};

// Brute force recursive
// TLE
