class Solution {
public:
    int climbStairs(int n) {
        if (n < 2)
            return 1;
        
        int a = 1; 
        int b = 1;        
        for (int i = 2; i < n+1; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        
        return b;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Climbing Stairs.

// Time complexity: O(n)
// Space complexity: O(1)