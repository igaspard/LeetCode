class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // pair: weight, idx
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeMinHeap;
        for (int i = 0; i < servers.size(); ++i) freeMinHeap.push({servers[i], i});

        // pair: times, idxs
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> busyMinHeap;
        vector<int> ans;
        long time = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            time = max(static_cast<long>(i), time);
            if (freeMinHeap.empty() && busyMinHeap.top().first > time) time = busyMinHeap.top().first;

            while (!busyMinHeap.empty() && busyMinHeap.top().first <= time) {
                auto cur = busyMinHeap.top();
                busyMinHeap.pop();
                int idx = static_cast<int>(cur.second);
                freeMinHeap.push({servers[idx], idx});
            }

            auto cur = freeMinHeap.top();
            freeMinHeap.pop();
            busyMinHeap.push({time + tasks[i], cur.second});
            ans.emplace_back(cur.second);
        }

        return ans;
    }
};

// Two Hepas
// Runtime: 424 ms, faster than 86.20% of C++ online submissions for Process Tasks Using Servers.
// Memory Usage: 119.5 MB, less than 97.76% of C++ online submissions for Process Tasks Using Servers.
