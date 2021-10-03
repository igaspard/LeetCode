class Solution {
public:
    int jump(vector<int>& nums) {
        const int N = nums.size();
        
        int end = 0, farthest = 0, ans = 0;
        for (int i = 0; i < N - 1; ++i) {
            farthest = max(farthest, nums[i] + i);
            if (end == i) {
                end = farthest;
                ++ans;
            }
        }
        
        return ans;
    }
};

// Greedy
// Runtime: 8 ms, faster than 98.29% of C++ online submissions for Jump Game II.
// Memory Usage: 16.3 MB, less than 71.61% of C++ online submissions for Jump Game II.