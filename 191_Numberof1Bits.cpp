class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n) {
            n &= (n-1);
            ans++;
        }
        
        return ans;
    }
};


// Runtime: 4 ms, faster than 56.29% of C++ online submissions for Number of 1 Bits.
// Memory Usage: 5.9 MB, less than 89.62% of C++ online submissions for Number of 1 Bits.