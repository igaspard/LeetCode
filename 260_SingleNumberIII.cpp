class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto it : nums) hash[it]++;

        vector<int> ans;
        for (auto it : hash) {
            if (it.second == 1) ans.emplace_back(it.first);
        }

        return ans;
    }
};

// Runtime: 12 ms, faster than 34.22% of C++ online submissions for Single Number III.
// Memory Usage: 10.8 MB, less than 14.92% of C++ online submissions for Single Number III.
