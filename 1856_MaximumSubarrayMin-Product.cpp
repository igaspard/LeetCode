class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const int N = nums.size();
        vector<long long> sum(N + 1);  // prefix sum
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + nums[i];

        vector<int> next(N);
        stack<int> s;
        for (int i = N - 1; i >= 0; --i) {
            while (!s.empty() && nums[i] <= nums[s.top()]) s.pop();
            next[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();
        vector<int> prev(N);
        for (int i = 0; i < N; ++i) {
            while (!s.empty() && nums[i] <= nums[s.top()]) s.pop();
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            long long sub_sum = next[i] == -1 ? sum[N] : sum[next[i]];
            if (prev[i] != -1) sub_sum -= sum[prev[i] + 1];

            ans = max(ans, (long long)nums[i] * sub_sum);
        }

        long long mod = 1e9 + 7;
        return ans % mod;
    }
};

// Monotonic Stack + Prefix Sum
// Monotonic Stack to find next & previous smaller numbers
// Use prefix sum w/ next and previous smaller numbers to calculate max subarray sum min product
// Runtime: 240 ms, faster than 85.71% of C++ online submissions for Maximum Subarray Min-Product.
// Memory Usage: 90.1 MB, less than 85.71% of C++ online submissions for Maximum Subarray Min-Product.
