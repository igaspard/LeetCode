class Solution {
   public:
    int rob(vector<int>& nums) {
        int pre = 0, cur = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int next = max(pre + nums[i], cur);
            pre = cur;
            cur = next;
        }

        return cur;
    }
};

// dp, 1D
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 7.7 MB, less than 71.13% of C++ online submissions for House Robber.

class Solution {
   public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return helper(memo, nums, 0);
    }

    int helper(vector<int>& memo, vector<int>& nums, int idx) {
        if (idx >= nums.size()) return 0;
        if (memo[idx] != -1) return memo[idx];

        memo[idx] = max(helper(memo, nums, idx + 1),               // skip this house, go to next
                        helper(memo, nums, idx + 2) + nums[idx]);  // rob current, go to next next one

        return memo[idx];
    }
};

// recursive w/ memo top down
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 7.8 MB, less than 40.20% of C++ online submissions for House Robber.