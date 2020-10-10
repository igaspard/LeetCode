class Solution {
   public:
    struct endCompare {
        bool operator()(const vector<int> &A, const vector<int> &B) { return A[2] > B[2]; }
    };

    bool carPooling(vector<vector<int>> &trips, int capacity) {
        sort(trips.begin(), trips.end(),
             [](const vector<int> &A, const vector<int> &B) { return A[1] < B[1]; });

        int maxCapsNeed = 0;
        int sum = 0;
        priority_queue<vector<int>, vector<vector<int>>, endCompare> minHeap;
        for (auto trip : trips) {
            while (!minHeap.empty() && trip[1] >= minHeap.top()[2]) {
                sum -= minHeap.top()[0];
                minHeap.pop();
            }
            minHeap.emplace(trip);
            sum += trip[0];

            maxCapsNeed = max(maxCapsNeed, sum);
        }

        return maxCapsNeed <= capacity;
    }
};

// minHeap, similar to meeting rooms II
// Runtime: 24 ms, faster than 49.79% of C++ online submissions for Car Pooling.
// Memory Usage: 10.3 MB, less than 5.94% of C++ online submissions for Car Pooling.