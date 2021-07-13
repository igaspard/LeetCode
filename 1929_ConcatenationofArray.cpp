class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums);
        for (auto n : nums) ans.emplace_back(n);
        return ans;
    }
};

// Runtime: 8 ms, faster than 50.00% of C++ online submissions for Concatenation of Array.
// Memory Usage: 12.6 MB, less than 100.00% of C++ online submissions for Concatenation of Array.