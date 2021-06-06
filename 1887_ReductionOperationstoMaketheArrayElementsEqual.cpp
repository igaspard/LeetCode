class Solution {
   public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int, int> freqs;
        for (auto num : nums) ++freqs[num];

        vector<pair<int, int>> data;
        for (auto freq : freqs) data.push_back({freq.first, freq.second});

        sort(data.begin(), data.end(), [](const pair<int, int>& A, const pair<int, int>& B) {
            if (A.first == B.first)
                return A.second < B.second;
            else
                return A.first > B.first;
        });

        int ans = 0;
        for (int i = 0; i < data.size() - 1; ++i) {
            ans += data[i].second;
            data[i + 1].second += data[i].second;
        }
        return ans;
    }
};

// sort
// Runtime: 332 ms, faster than 100.00% of C++ online submissions for Reduction Operations to Make the Array
// Elements Equal. Memory Usage: 131.7 MB, less than 33.33% of C++ online submissions for Reduction Operations
// to Make the Array Elements Equal.
