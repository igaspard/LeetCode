class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        bool *bPrime = (bool *)calloc(n, sizeof(bool));    
        for (int i = 2; i*i <= n; i++) {
            if(bPrime[i]) {
                continue;
            }
            else {
                for (int j = i*i; j < n; j+=i) 
                    bPrime[j] = true;
            }
        }
    
        int ans = 1;
        for (int i = 3; i < n; i+=2) {
            if(bPrime[i]==false) 
                ans++;
        }
        free(bPrime);
        return ans;
    }
};

// Use Sieve of Eratosthenes 1. only need to check square roots of n, 2. update i^2+i, i^2+2i
// Runtime: 8 ms, faster than 99.65% of C++ online submissions for Count Primes.
// Memory Usage: 11.7 MB, less than 8.33% of C++ online submissions for Count Primes.