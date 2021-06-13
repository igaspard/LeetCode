class Solution {
   public:
    struct freqCmp {
        bool operator()(const pair<string, int> &A, const pair<string, int> &B) {
            if (A.second == B.second)
                return A.first > B.first;  //  lower alphabetical order
            else
                return A.second < B.second;  // freq increasing order
        };
    };

    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> hash;
        for (auto w : words) ++hash[w];

        priority_queue<pair<string, int>, vector<pair<string, int>>, freqCmp> maxHeap;
        for (auto it : hash) minHeap.push({it.first, it.second});

        vector<string> ans;
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(minHeap.top().first);
            minHeap.pop();
        }

        return ans;
    }
};

// heap
// Runtime: 16 ms, faster than 36.95% of C++ online submissions for Top K Frequent Words.
// Memory Usage: 12.7 MB, less than 27.97% of C++ online submissions for Top K Frequent Words.
