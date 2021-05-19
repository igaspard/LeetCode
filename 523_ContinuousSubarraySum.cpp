class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<int> preSum(N+1);
        preSum[0] = 0;
        
        for (int i = 0; i < N; ++i) {
            preSum[i+1] = preSum[i] + nums[i];
        }

        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if ((preSum[j+1] - preSum[i]) % k == 0) return true;
            }
        }
        
        return false;
    }
};

// prefixSum
// TLE
