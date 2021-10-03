class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, ans = 0;
        for (auto n : nums) {
            if (n == 1) ans = max(ans, ++cnt);
            else cnt = 0;
        }
        
        return ans;
    }
};

// Runtime: 32 ms, faster than 78.19% of C++ online submissions for Max Consecutive Ones.
// Memory Usage: 36.2 MB, less than 66.86% of C++ online submissions for Max Consecutive 