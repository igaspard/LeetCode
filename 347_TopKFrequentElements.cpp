class Solution {
   public:
    struct pairCompare {
        char operator()(const pair<int, int> &x, pair<int, int> &y) { return x.second > y.second; }
    };

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> hash;
        for (auto num : nums) hash[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, pairCompare> minHeap;
        for (auto entry : hash) {
            minHeap.emplace(entry);
            if (minHeap.size() > k) minHeap.pop();
        }

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(minHeap.top().first);
            minHeap.pop();
        }

        return ans;
    }
};

// Hash table and minHeap
// Time complexity: O(nlogk)
// Space complexity: O(n)
// Runtime: 24 ms, faster than 99.04% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 14 MB, less than 8.96% of C++ online submissions for Top K Frequent Elements.