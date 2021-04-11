class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (auto it : nums) {
            if (!it) return 0;
            if (it < 0) ans *= -1;
        }
        
        return ans;
     }
};

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Sign of the Product of an Array.
// Memory Usage: 10 MB, less than 85.71% of C++ online submissions for Sign of the Product of an Array.