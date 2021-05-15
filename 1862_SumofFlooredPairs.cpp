class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        vector<int> freq(100001, 0);
        vector<int> prefix_freq(100002, 0);
        int mx = -1;
        for (auto n : nums) {
            ++freq[n];
            mx = max(mx, n);
        }
        for (int i = 1; i < freq.size(); ++i) 
            prefix_freq[i] = freq[i] + prefix_freq[i-1];

        long long ans = 0;
        const long long MOD = 1e9 + 7;
        for (int i = 1; i <= mx; ++i) {
            int val = 1;
            while (true) {
                int start = val * i;
                int end = (val + 1) * i - 1;
                if (end >= mx) end = mx;
                ans += val * freq[i] * (prefix_freq[end] - prefix_freq[start-1]);
                ans %= MOD;
                if (end == mx) break;
                ++val;
            }
        }

        return ans;
    }
};

// Prefix Sum + frequency
// Runtime: 500 ms, faster than 25.00% of C++ online submissions for Sum of Floored Pairs.
// Memory Usage: 133.4 MB, less than 100.00% of C++ online submissions for Sum of Floored Pairs.