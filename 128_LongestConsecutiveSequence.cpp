class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record;
        for (auto n : nums) record.insert(n);

        int ans = 0;
        for (auto n : nums) {
            if (record.count(n) == 0) continue;
            record.erase(n);

            int pre = n - 1, next = n + 1;
            while (record.count(pre) != 0) record.erase(pre--);
            while (record.count(next) != 0) record.erase(next++);
            ans = max(ans, next - pre - 1);
        }

        return ans;
    }
};

// Hash
// Runtime: 76 ms, faster than 69.62% of C++ online submissions for Longest Consecutive Sequence.
// Memory Usage: 30.9 MB, less than 47.05% of C++ online submissions for Longest Consecutive Sequence.