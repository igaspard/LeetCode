class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left) {
            right = right & (right - 1);
        }
        
        return right;
    }
};

// Runtime: 4 ms, faster than 92.70% of C++ online submissions for Bitwise AND of Numbers Range.
// Memory Usage: 5.9 MB, less than 30.76% of C++ online submissions for Bitwise AND of Numbers Range.

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0) return 0;
        
        int ans = 1;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            ans <<= 1;
        }
        
        return ans * left;
    }
};

// Runtime: 8 ms, faster than 74.60% of C++ online submissions for Bitwise AND of Numbers Range.
// Memory Usage: 5.9 MB, less than 30.76% of C++ online submissions for Bitwise AND of Numbers Range.
