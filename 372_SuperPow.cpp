class Solution {
   public:
    const int MOD = 1337;
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;

        int last = b.back();
        b.pop_back();

        int part1 = fastPow(a, last);
        int part2 = fastPow(superPow(a, b), 10);
        return (part1 * part2) % MOD;
    }

    int fastPow(int x, int n) {
        if (n == 0) return 1;
        x %= MOD;

        if (n % 2 == 0) {
            int half = fastPow(x, n / 2);
            return half * half % MOD;
        } else
            return x * fastPow(x, n - 1) % MOD;
    }
};

// fast power, logN
// (a * b) % k = (a % k) * (b % k ) % k to deal with overflow
// Runtime: 12 ms, faster than 62.16% of C++ online submissions for Super Pow.
// Memory Usage: 11.7 MB, less than 57.00% of C++ online submissions for Super Pow.
