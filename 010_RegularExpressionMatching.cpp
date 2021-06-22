class Solution {
   public:
    bool isMatch(string s, string p) {
        const int M = s.length(), N = p.length();
        bool dp[M + 1][N + 1];  // define dp[i][j] as s[0..i] p[0..j] match?
        for (int i = 0; i <= M; ++i)
            for (int j = 0; j <= N; ++j) dp[i][j] = false;

        dp[0][0] = true;
        for (int j = 2; j <= N; ++j)
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];

        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (j > 1 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];

                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) dp[i][j] = dp[i][j] | dp[i - 1][j];
                }
            }
        }

        return dp[M][N];
    }
};

// dp
// Runtime: 4 ms, faster than 85.59% of C++ online submissions for Regular Expression Matching.
// Memory Usage: 6.1 MB, less than 96.31% of C++ online submissions for Regular Expression Matching.

class Solution {
   public:
    unordered_map<string, bool> memo;
    bool isMatch(string s, string p) { return dp(s, 0, p, 0); }

    bool dp(string s, int i, string p, int j) {
        const int M = s.length(), N = p.length();
        // base cases
        if (j == N) return i == M;

        if (i == M) {
            // s already empty, remain p must be even like "b*c*" pair char w/ '*', if not return false
            if ((N - j) % 2 == 1) return false;  // pattern like a*b*c* length should be even

            // check a*b*c* pattern
            for (; j + 1 < N; j += 2)
                if (p[j + 1] != '*') return false;

            return true;
        }

        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];

        bool ans = false;
        if (s[i] == p[j] || p[j] == '.') {
            if (j < N - 1 && p[j + 1] == '*') {
                ans = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
            } else {
                ans = dp(s, i + 1, p, j + 1);
            }
        } else {
            if (j < N - 1 && p[j + 1] == '*') {
                ans = dp(s, i, p, j + 2);
            } else {
                ans = false;
            }
        }

        memo[key] = ans;

        return ans;
    }
};

// recursive top down w/ memo
// Runtime: 12 ms, faster than 36.45% of C++ online submissions for Regular Expression Matching.
// Memory Usage: 24.4 MB, less than 5.07% of C++ online submissions for Regular Expression Matching.
