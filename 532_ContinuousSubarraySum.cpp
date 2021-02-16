/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = -1;

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (k != 0) sum = sum % k;
            if (hash.count(sum)) {
                if ((i - hash[sum]) > 1) return true;
            } else {
                hash[sum] = i;
            }
        }

        return false;
    }
};
// @lc code=end

// PrefixSum