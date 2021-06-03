class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        int mx = 0;
        for (int i = 0; i < N / 2 ; ++i) {
            int sum = nums[i] + nums[N-i-1];
            mx = max(mx, sum);
        }

        return mx;
    }
};

// sort
// Runtime: 320 ms, faster than 53.52% of C++ online submissions for Minimize Maximum Pair Sum in Array.
// Memory Usage: 96.3 MB, less than 18.41% of C++ online submissions for Minimize Maximum Pair Sum in Array.
