class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        long a121 = 6, a123 = 6, b121, b123;
        
        for (int i = 1; i < n; ++i) {
            b121 = a121 * 3 + a123 * 2;
            b123 = a121 * 2 + a123 * 2;
            a121 = b121 % MOD;
            a123 = b123 % MOD;
        }
        
        return (a121 + a123) % MOD;
    }
};

// DP
// pattern 121: 121, 131, 212, 232, 313, 323.
// pattern 123: 123, 132, 213, 231, 312, 321.
// Patter 121 can be followed by: 212, 232, 313, 213, 312
// Patter 123 can be followed by: 212, 232, 231, 312
// Time O(N), Space O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Ways to Paint N × 3 Grid.
// Memory Usage: 6 MB, less than 61.34% of C++ online submissions for Number of Ways to Paint N × 3 Grid.

class Solution {
public:
    int numOfWays(int n) {
        return dfs(n, 0, 0, 0);
    }
private:
    int memo[5001][4][4][4] = {};
    vector<int> colors = {1, 2, 3};
    const int MOD = 1e9 + 7;
    int dfs(int n, int i, int j, int k) {
        if (n == 0) return 1;
        if (memo[n][i][j][k] != 0) return memo[n][i][j][k];
        
        int ans = 0;      
        for (auto a : colors) {
            if (a == i) continue;
            for (auto b : colors) {
                if (b == j || b == a) continue;
                for (auto c : colors) {
                    if (c == k || c == b) continue;
                    ans += dfs(n - 1, a, b, c);
                    ans %= MOD;
                }
            }
        }
        
        memo[n][i][j][k] = ans;
        return memo[n][i][j][k];
    }
};

// recursive w/ memo top down
// Runtime: 124 ms, faster than 17.43% of C++ online submissions for Number of Ways to Paint N × 3 Grid.
// Memory Usage: 10.6 MB, less than 17.17% of C++ online submissions for Number of Ways to Paint N × 3 Grid.