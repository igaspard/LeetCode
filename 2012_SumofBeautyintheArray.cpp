class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        const int N = nums.size();
        vector<int> prefix(N, nums[0]), suffix(N, nums[N-1]);
        for (int i = 1; i < N; ++i) prefix[i] = max(prefix[i-1], nums[i]);
        for (int i = N - 2; i >= 0; --i) suffix[i] = min(suffix[i+1], nums[i]);
        
        int ans = 0;
        for (int i = 1; i < N - 1; ++i) {
            if (nums[i] > prefix[i-1] && nums[i] < suffix[i+1]) ans += 2;
            else if (nums[i-1] < nums[i] && nums[i] < nums[i+1]) ++ans;
        }
        
        return ans;
    }
};

// prefix sum
// time prefix O(N)
// Runtime: 148 ms, faster than 85.71% of C++ online submissions for Sum of Beauty in the Array.
// Memory Usage: 88.4 MB, less than 7.14% of C++ online submissions for Sum of Beauty in the Array.