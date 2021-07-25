class Solution {
   public:
    struct endCompare {
        bool operator()(const vector<int> &A, vector<int> &B) { return A[1] > B[1]; }
    };

    int smallestChair(vector<vector<int>> &times, int targetFriend) {
        const int N = times.size();
        vector<vector<int>> temps(times);
        int i = 0;
        for (auto &t : temps) t.emplace_back(i++);

        sort(temps.begin(), temps.end(),
             [](const vector<int> &A, const vector<int> &B) { return A[0] < B[0]; });

        vector<int> ans(N);
        vector<bool> chairs(N, false);
        priority_queue<vector<int>, vector<vector<int>>, endCompare> minHeap;
        for (auto t : temps) {
            while (!minHeap.empty() && t[0] >= minHeap.top()[1]) {
                chairs[ans[minHeap.top()[2]]] = false;
                minHeap.pop();
            }

            minHeap.emplace(t);
            for (int i = 0; i < N; ++i) {
                if (chairs[i] == false) {
                    ans[t[2]] = i;
                    chairs[i] = true;
                    break;
                }
            }
        }

        return ans[targetFriend];
    }
};

Runtime: 896 ms, faster than 14.29% of C++ online submissions for The Number of the Smallest Unoccupied Chair.
Memory Usage: 86.3 MB, less than 14.29% of C++ online submissions for The Number of the Smallest Unoccupied Chair.