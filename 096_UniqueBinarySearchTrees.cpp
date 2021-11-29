class Solution {
   public:
    int numTrees(int n) {
        long c = 1;
        for (int i = 0; i < n; ++i) c = c * 2 * (2 * i + 1) / (i + 2);

        return c;
    }
};

// Mathematical
// Time complexity: O(n)
// Space complexity: O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Binary Search Trees.
// Memory Usage: 6.1 MB, less than 44.50% of C++ online submissions for Unique Binary Search Trees.

class Solution {
   public:
    int numTrees(int n) {
        vector<int> c(n + 1, 0);
        c[0] = c[1] = 1;

        for (int i = 2; i <= n; ++i)
            for (int j = 0; j < i; ++j) c[i] += c[j] * c[i - j - 1];

        return c[n];
    }
};

// DP to calculate Catalan Number
// c(n) = c(0)*c(n-1) + c(1)*c(n-2) + c(2)*c(n-3) + ... + c(n-3)*c(2) + c(n-2)*c(1) + c(n-1)*c(0)
// Space complexity: O(n)
// Time complexity: O(n^2)
// Runtime: 4 ms, faster than 11.46% of C++ online submissions for Unique Binary Search Trees.
// Memory Usage: 6.1 MB, less than 36.95% of C++ online submissions for Unique Binary Search Trees.