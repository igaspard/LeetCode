class Solution {
   public:
    int climbStairs(int n) {
        if (n < 2) return 1;

        int a = 1, b = 1;
        for (int i = 2; i <= n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};

// DP f(n) = f(n-1) + f(n-2), f(0) = 1, f(1) = 1
// Time complexity: O(n)
// Space complexity: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Climbing Stairs.