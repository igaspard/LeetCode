class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        int pre = 1, cur = 1;
        for (int i = 3; i <= n; ++i) {
            int sum = cur + pre;
            pre = cur;
            cur = sum;
        }
            
        return cur;
    }
};

// dp 
// Time complexity: N * O(1) = O(N)
// Space complexity: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
// Memory Usage: 5.9 MB, less than 36.78% of C++ online submissions for Fibonacci Number.

class Solution {
   public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        vector<int> dp(n + 1, 0);
        dp[1] = dp[2] = 1;

        for (int i = 3; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};

// dp, bottom up
// Time complexity: N * O(1) = O(N)
// Space complexity: O(N)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
// Memory Usage: 6.1 MB, less than 7.81% of C++ online submissions for Fibonacci Number.

class Solution {
   public:
    int fib(int n) {
        if (n == 0) return 0;
        vector<int> memo(n + 1, 0);

        return helper(memo, n);
    }

    int helper(vector<int> &memo, int N) {
        if (N == 1 || N == 2) return 1;

        if (memo[N] != 0) return memo[N];
        memo[N] = helper(memo, N - 1) + helper(memo, N - 2);
        return memo[N];
    }
};

// Recursive w/ memo top down
// Time complexity: N * O(1) = O(N)
// Space complexity: O(N)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
// Memory Usage: 6.2 MB, less than 7.81% of C++ online submissions for Fibonacci Number.

class Solution {
   public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        return fib(n - 1) + fib(n - 2);
    }
};

// Recursive
// Time complexity: 2^N * O(1) = O(2^N)
// Runtime: 12 ms, faster than 30.68% of C++ online submissions for Fibonacci Number.
// Memory Usage: 6 MB, less than 36.78% of C++ online submissions for Fibonacci Number.