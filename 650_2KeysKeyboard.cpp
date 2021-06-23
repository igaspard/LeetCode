class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        
        for (int i = 2; i < n; ++i)
            if (n % i == 0) return i + minSteps(n / i);
        
        return n;
    }
};

// recursive
// It take 2 ops to double, 3 ops to triple, ...
// if n % 2 == 0, then f(n) = f(n/2) + 2
// if n % 3 == 0, then f(n) = f(n/3) + 3
// 2 * 2 = 2 + 2; 2 * 3 > 2 + 3; 4 * 4 > 4 + 4; so it is always better to divide whenever possible.
// now it became a problem for finding all possible factors;
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for 2 Keys Keyboard.
// Memory Usage: 5.7 MB, less than 97.33% of C++ online submissions for 2 Keys Keyboard.