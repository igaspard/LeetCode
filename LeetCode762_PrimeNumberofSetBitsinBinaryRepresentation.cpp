class Solution {
public:
    unsigned int countSetBits(int n) {
        unsigned int count = 0;
        while (n) {
            n &= (n-1);
            count++;
        }
        return count;
    }
    bool isPrime(int n) {
        if (n <= 1)
            return false;

        for(int i = 2; i < n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for(int i = L; i <= R; i++) {
            int setbits = countSetBits(i);
            if (isPrime(setbits))
                ans++;
        }
        return ans;
    }
};
