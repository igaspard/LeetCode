class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        const int N = nums.size();
        deque<int> suffix_sum;
        int sum = 0;
        for (int i = N - 1; i >= 0; --i) {
            sum += nums[i];
            suffix_sum.push_front(sum);
        }

        int prefix_sum = 0;
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            prefix_sum += nums[i];
            ans.emplace_back(nums[i] * (2*i-N+1) - prefix_sum + suffix_sum[i]);
        }

        return ans;
    }
};

// Prefix Sum
// Runtime: 116 ms, faster than 39.50% of C++ online submissions for Sum of Absolute Differences in a Sorted Array.
// Memory Usage: 90.5 MB, less than 13.91% of C++ online submissions for Sum of Absolute Differences in a Sorted Array.
