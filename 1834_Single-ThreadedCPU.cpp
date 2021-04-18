class Solution {
   public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        const size_t N = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < N; ++i) tasks[i].emplace_back(i);
        sort(tasks.begin(), tasks.end());

        vector<int> ans;
        long time = 1;
        int idx = 0;
        while (ans.size() != N) {
            if (minHeap.empty()) time = max(time, (long)tasks[idx][0]);

            while (idx < N && time >= tasks[idx][0]) {
                minHeap.emplace(tasks[idx][1], tasks[idx][2]);
                ++idx;
            }

            auto it = minHeap.top();
            minHeap.pop();
            time += it.first;
            ans.emplace_back(it.second);
        }

        return ans;
    }
};

// sort + minHeap
// Runtime: 548 ms, faster than 28.57% of C++ online submissions for Single-Threaded CPU.
// Memory Usage: 129.4 MB, less than 14.29% of C++ online submissions for Single-Threaded CPU.