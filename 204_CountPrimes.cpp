class Solution {
   public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        bool isPrimes[n];
        isPrimes[0] = false;
        isPrimes[1] = false;
        for (int i = 2; i < n; ++i) isPrimes[i] = true;

        for (int i = 2; i * i < n; ++i)
            if (isPrimes[i])
                for (int j = i * i; j < n; j += i) isPrimes[j] = false;

        int ans = 0;
        for (auto iP : isPrimes)
            if (iP) ++ans;
        return ans;
    }
};

// Use Sieve of Eratosthenes 1. only need to check square roots of n, 2. update i^2+i, i^2+2i
// Runtime: 40 ms, faster than 92.90% of C++ online submissions for Count Primes.
// Memory Usage: 11.4 MB, less than 43.90% of C++ online submissions for Count Primes.

class Solution {
   public:
    int countPrimes(int n) {
        int ans = 0;
        for (int i = 2; i < n; ++i)
            if (isPrimes(i)) ++ans;

        return ans;
    }

    bool isPrimes(int n) {
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0) return false;

        return true;
    }
};

// TLE
