class Solution {
   public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return fastPow(x, N);
    }

    double fastPow(double x, long long n) {
        if (n == 0 || x == 1.0) return 1.0;

        if (n % 2 == 0) {
            double half = fastPow(x, n / 2);
            return half * half;
        } else
            return x * fastPow(x, n - 1);
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
// Memory Usage: 5.9 MB, less than 40.06% of C++ online submissions for Pow(x, n).