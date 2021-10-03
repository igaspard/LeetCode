class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        int cur = 1, pre = 1, ppre = 0;
        for (int i = 3; i < n + 1; ++i) {
            int tmp = cur + pre + ppre;
            ppre = pre;
            pre = cur;
            cur = tmp;
        }
        
        return cur;
    }
};

// DP
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-th Tribonacci Number.
// Memory Usage: 5.9 MB, less than 45.89% of C++ online submissions for N-th Tribonacci Number.