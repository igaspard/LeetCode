class Solution {
public:
    int countGoodNumbers(long long n) {
        long long pow5, pow4;
        if (n % 2 == 0) {
            long long half = (long long)n / 2;
            pow5 = power(5, half) % MOD;
            pow4 = power(4, half) % MOD;
        } else {
            long long half = (long long)n / 2;
            pow5 = power(5, half + 1) % MOD;
            pow4 = power(4, half) % MOD;
        }

        return pow5 * pow4 % MOD;
    }
private:
    const long long MOD = 1e9 + 7;
    long long power(int n, long long x) {
        if (x == 0) return 1;

        long long half = power(n, x / 2);

        if (x % 2 == 0)
            return (half * half) % MOD;
        else
            return (((half * half) % MOD) * n) % MOD;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Good Numbers.
// Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Count Good Numbers.