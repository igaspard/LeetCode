class Solution {
   public:
    struct freqCompare {
        const char operator()(const pair<char, int> &x, const pair<char, int> &y) {
            return x.second < y.second;
        }
    };
    string frequencySort(string s) {
        unordered_map<char, int> hash;
        for (auto c : s) hash[c]++;

        priority_queue<pair<char, int>, vector<pair<char, int>>, freqCompare> maxHeap;

        for (auto entry : hash) maxHeap.emplace(entry);

        string sorted = "";
        const int N = maxHeap.size();
        for (int i = 0; i < N; ++i) {
            auto it = maxHeap.top();
            for (int j = 0; j < it.second; ++j) sorted += it.first;
            maxHeap.pop();
        }

        return sorted;
    }
};

// Hash table to calculate the frequency and use heap to sort the entries
// Time complexity: O(nlogn)
// Space complexity: O(n)
// Runtime: 24 ms, faster than 85.40% of C++ online submissions for Sort Characters By Frequency.
// Memory Usage: 8.6 MB, less than 6.57% of C++ online submissions for Sort Characters By Frequency.