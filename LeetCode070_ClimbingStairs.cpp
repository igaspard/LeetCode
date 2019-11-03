class Solution {
public:
    int climbStairs(int n) {
        if (n < 2)
            return 1;
        
        int s[n+1];
        s[0] = 1; s[1] = 1;
        
        for (int i = 2; i < n+1; i++)
            s[i] = s[i-1] + s[i-2];
        
        return s[n];
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Climbing Stairs.

// Time complexity: O(n)
// Space complexity: O(n)