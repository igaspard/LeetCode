class Solution {
public:
    int superEggDrop(int k, int n) {
        int dp[k+1][n+1];
        
        for (int j = 0; j <= k; ++j) 
            for (int i = 0; i <= n; ++i)
                dp[j][i] = 0;
        
        int m = 0;
        while (dp[k][m] < n) {
            ++m;
            for (int K = 1; K <= k; ++K)
                dp[K][m] = dp[K][m-1] + dp[K-1][m-1] + 1;
        }
            
        return m;
    }
};

// dp, define dp[k][m] as how many floors when you have k eggs and m times to drop the eggs
// once we found the dp[k][m] == n means that the m is the answer of
// time complexity: O(KN)
// space complexity: O(KN)
// Runtime: 8 ms, faster than 85.24% of C++ online submissions for Super Egg Drop.
// Memory Usage: 9.4 MB, less than 87.70% of C++ online submissions for Super Egg Drop.

class Solution {
   public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> memo(k + 1, vector<int>(n + 1, -1));

        return dp(memo, k, n);
    }

    int dp(vector<vector<int>> &memo, int k, int n) {
        if (k == 1) return n;
        if (n == 0) return 0;

        if (memo[k][n] != -1) return memo[k][n];

        int ans = INT_MAX;
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // ans = min(ans, max(dp(memo, k - 1, i - 1), dp(memo, k, n - i)) + 1);
            int broken = dp(memo, k - 1, mid - 1);
            int not_broken = dp(memo, k, n - mid);

            if (broken > not_broken) {
                right = mid - 1;
                ans = min(ans, broken + 1);
            } else {
                left = mid + 1;
                ans = min(ans, not_broken + 1);
            }
        }

        memo[k][n] = ans;

        return memo[k][n];
    }
};

// recursive with memo plus binary search
// instead of find the min times 1 ~ N, find the min times by using a binary search
// ans = min(ans, max(dp(memo, k - 1, i - 1), dp(memo, k, n - i)) + 1);
// dp(memo, k - 1, i - 1) is increasing, dp(memo, k, n - i) is decreasing
// when we are are find the min of two of those, it actually find the intersection
// time complexity: O(KNlogN)
// space complexity: O(KN)
// Runtime: 96 ms, faster than 37.17% of C++ online submissions for Super Egg Drop.
// Memory Usage: 29.6 MB, less than 21.22% of C++ online submissions for Super Egg Drop.

class Solution {
   public:
    int superEggDrop(int k, int n) {
        int dp[k + 1][n + 1];
        // if (k == 1) return n;
        for (int i = 0; i <= n; ++i) dp[1][i] = i;

        // if (n == 0) return 0;
        for (int j = 1; j <= k; ++j) dp[j][0] = 0;

        for (int j = 2; j <= k; ++j) {
            for (int i = 1; i <= n; ++i) {
                int ans = INT_MAX;
                for (int x = 1; x <= i; ++x) {
                    ans = min(ans, max(dp[j - 1][x - 1], dp[j][i - x]) + 1);
                }
                dp[j][i] = ans;
            }
        }

        return dp[k][n];
    }
};

// dp bottom up, define dp[k][n] how many times to test when we have k eggs & n floor for test
// 1. state -> how many eggs & how many floor to test
// 2. choose -> which floor to test
// 3. transfer function
//      if eggs breaks at floor i, then eggs become k-1 & search range [1..i-1], total i-1 floors
//      if eggs didn't break at floor i, then eggs still k & search [i+1..N], total N-i floors
// 4. base cases -> if (K == 1) return N. If there is only one egg, you need to search n times from 1 to n
//               -> if (N == 0) return 0. If only 0 floor, then we dont need to test.
// TLE
// Time complexity: O(KN^2)
// space complexity: O(KN)

class Solution {
   public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> memo(k + 1, vector<int>(n + 1, -1));

        return dp(memo, k, n);
    }

    int dp(vector<vector<int>> &memo, int k, int n) {
        if (k == 1) return n;
        if (n == 0) return 0;

        if (memo[k][n] != -1) return memo[k][n];

        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, max(dp(memo, k - 1, i - 1), dp(memo, k, n - i)) + 1);
        }

        memo[k][n] = ans;

        return memo[k][n];
    }
};

// recursive with memo
// TLE