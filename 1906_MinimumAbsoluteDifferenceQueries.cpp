class Solution {
   public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        const int MAX_NUM = 100;
        const int MAX_LEN = 100000;
        const int N = nums.size();
        const int M = queries.size();
        int prefix[MAX_LEN + 1][MAX_NUM + 1] = {}, freq[MAX_NUM + 1] = {};
        for (int i = 0; i < N; ++i) {
            ++freq[nums[i]];
            for (int j = 0; j <= MAX_NUM; ++j) prefix[i + 1][j] = freq[j];
        }

        vector<int> ans;
        for (auto query : queries) {
            int start = query[0], end = query[1];
            int cnt[MAX_NUM + 1] = {};
            for (int i = 0; i <= MAX_NUM; ++i) cnt[i] = prefix[end + 1][i] - prefix[start][i];

            int diff = INT_MAX, prev = -1;
            for (int i = 1; i <= MAX_NUM; ++i) {
                if (cnt[i] == 0) continue;
                if (prev != -1 && i - prev < diff) diff = i - prev;
                prev = i;
            }
            if (diff == INT_MAX)
                ans.emplace_back(-1);
            else
                ans.emplace_back(diff);
        }

        return ans;
    }
};

// prefix sum
// Runtime: 460 ms, faster than 100.00% of C++ online submissions for Minimum Absolute Difference Queries.
// Memory Usage: 129.5 MB, less than 50.00% of C++ online submissions for Minimum Absolute Difference Queries.

class Solution {
   public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto query : queries) {
            int diff = INT_MAX;
            for (int i = query[0]; i < query[1]; ++i) {
                for (int j = i + 1; j <= query[1]; ++j) {
                    if (nums[j] != nums[i]) diff = min(diff, abs(nums[j] - nums[i]));
                }
            }
            if (diff == INT_MAX)
                ans.emplace_back(-1);
            else
                ans.emplace_back(diff);
        }

        return ans;
    }
};

// Brute force
// TLE