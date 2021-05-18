class Solution {
public:
    int concatenatedBinary(int n) {
        int shift = 0;
        uint64_t ans = 1;
        const uint64_t MOD = 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            shift = (int)(log2(i) + 1);
            ans = ((ans << shift) + i) % MOD;
        }

        return ans;
    }
};

// bit operation
// Runtime: 72 ms, faster than 63.21% of C++ online submissions for Concatenation of Consecutive Binary Numbers.
// Memory Usage: 5.9 MB, less than 46.54% of C++ online submissions for Concatenation of Consecutive Binary Numbers.