class Solution {
public:
    bool isThree(int n) {
        int divisors_cnt = 1;
        
        for (int i = 2; i <= n; ++i) {
            if (n % i == 0) ++divisors_cnt;
            if (divisors_cnt > 3) return false;
        }
        
        return divisors_cnt == 3;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Three Divisors.
// Memory Usage: 5.7 MB, less than 100.00% of C++ online submissions for Three Divisors.