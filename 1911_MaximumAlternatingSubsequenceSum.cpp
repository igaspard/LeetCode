class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even = 0, odd = 0;

        for (int i = 1; i < nums.size() + 1; ++i) {
            long long next_even = max(odd + nums[i-1], even);
            long long next_odd = max(even - nums[i-1], odd);
            even = next_even;
            odd = next_odd;
        }
        
        return even;
    }
};

// dp, since we only need previous results, compress the dp array into 2 variables
// space complexity: O(1)
// Runtime: 148 ms, faster than 100.00% of C++ online submissions for Maximum Alternating Subsequence Sum.
// Memory Usage: 91 MB, less than 100.00% of C++ online submissions for Maximum Alternating Subsequence Sum.

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const int N = nums.size();
        enum NUM { EVEN = 0, ODD };
        long long dp[2][N+1];
        dp[EVEN][0] = dp[ODD][0] = 0; // base cases
        
        for (int i = 1; i < N + 1; ++i) {
            dp[EVEN][i] = max(dp[ODD][i-1] + nums[i-1], dp[EVEN][i-1]);
            dp[ODD][i] = max(dp[EVEN][i-1] - nums[i-1], dp[ODD][i-1]);
        }
        
        return dp[EVEN][N];
    }
};

// dp
// define dp[0][i] as max alternate sum end with nums[i] as last even-indexed number
// define dp[1][i] as max alternate sum end with nums[i] as last odd-indexed number
// base cases dp[EVEN][0] = dp[ODD][0] = 0;
// transfer function 
// dp[EVEN][i] = max(dp[ODD][i-1] + nums[i-1], dp[EVEN][i-1]); // choose nums[i-1] as last even-indexed number or not choose
// dp[ODD][i] = max(dp[EVEN][i-1] - nums[i-1], dp[ODD][i-1]); // choose nums[i-1] as last odd-indexed number or not choose
// Time complexity: O(N)
// Space complexity: O(2*N)
// Runtime: 164 ms, faster than 100.00% of C++ online submissions for Maximum Alternating Subsequence Sum.
// Memory Usage: 92.7 MB, less than 100.00% of C++ online submissions for Maximum Alternating Subsequence Sum.