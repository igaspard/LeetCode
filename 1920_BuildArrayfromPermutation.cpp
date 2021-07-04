class Solution {
   public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for (auto n : nums) ans.emplace_back(nums[n]);

        return ans;
    }
};

// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Build Array from Permutation.
// Memory Usage: 16.8 MB, less than 33.33% of C++ online submissions for Build Array from Permutation.