class Solution {
   public:
    struct endCompare {
        bool operator()(const vector<int> &A, vector<int> &B) { return A[1] > B[1]; }
    };

    int minMeetingRooms(vector<vector<int>> &intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

        int minRooms = 0;
        priority_queue<vector<int>, vector<vector<int>>, endCompare> minHeap;
        for (auto interval : intervals) {
            while (!minHeap.empty() && interval[0] >= minHeap.top()[1]) minHeap.pop();

            minHeap.emplace(interval);

            minRooms = max(minRooms, (int)minHeap.size());
        }

        return minRooms;
    }
};

// minHeap
// Time complexity: O(nlogn) sort O(nlogn), minHeap n * O(logn)
// Space complexity: O(N)
// Runtime: 44 ms, faster than 58.03% of C++ online submissions for Meeting Rooms II.
// Memory Usage: 13.1 MB, less than 9.02% of C++ online submissions for Meeting Rooms II.