class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();
        
        int farthest = 0;
        for (int i = 0; i < N - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (farthest <= i) return false;
        }
        
        return farthest >= N - 1;
    }
};

// greedy solution
// Runtime: 115 ms, faster than 26.89% of C++ online submissions for Jump Game.
// Memory Usage: 48.4 MB, less than 19.77% of C++ online submissions for Jump Game.