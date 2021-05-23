class Solution {
   public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto n : nums) ++hash[n];

        int ans = 0;
        for (auto entry : hash)
            if (hash.count(entry.first + 1) != 0) ans = max(ans, entry.second + hash[entry.first + 1]);

        return ans;
    }
};

// Hash Table
// Runtime: 76 ms, faster than 73.89% of C++ online submissions for Longest Harmonious Subsequence.
// Memory Usage: 40.1 MB, less than 47.22% of C++ online submissions for Longest Harmonious Subsequence.

class Solution {
   public:
    int findLHS(vector<int>& nums) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            while (i > 0 && i < N - 1 && nums[i] == nums[i - 1]) ++i;
            for (int j = i + 1; j < N; ++j) {
                if ((nums[j] - nums[i]) == 1) {
                    ans = max(ans, j - i + 1);
                } else if ((nums[j] - nums[i]) > 1)
                    break;
            }
        }

        return ans;
    }
};

// sort + two pointers
// Runtime: 56 ms, faster than 93.89% of C++ online submissions for Longest Harmonious Subsequence.
// Memory Usage: 32.4 MB, less than 97.22% of C++ online submissions for Longest Harmonious Subsequence.
