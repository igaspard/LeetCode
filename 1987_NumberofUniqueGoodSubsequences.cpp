class Solution {
   public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int MOD = 1e9 + 7, end0 = 0, end1 = 0;
        for (auto ch : binary) {
            if (ch == '0')
                end0 = (end0 + end1) % MOD;
            else
                end1 = (end0 + end1 + 1) % MOD; // +1 to count '1'
        }

        int has0 = binary.find("0") != string::npos;
        return (end0 + end1 + has0) % MOD;
    }
};

// DP
// Runtime: 28 ms, faster than 100.00% of C++ online submissions for Number of Unique Good Subsequences.
// Memory Usage: 12.2 MB, less than 90.91% of C++ online submissions for Number of Unique Good Subsequences.
