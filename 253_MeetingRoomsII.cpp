class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto interval : intervals) {
            ++m[interval[0]];
            --m[interval[1]];
        }
        
        int ans = 0, rooms = 0;
        for (auto it : m) 
            ans = max(ans, rooms += it.second);
        
        return ans;
    }
};

// Runtime: 16 ms, faster than 83.60% of C++ online submissions for Meeting Rooms II.
// Memory Usage: 14 MB, less than 14.41% of C++ online submissions for Meeting Rooms II.

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
        priority_queue<vector<int>, vector<vector<int>>> maxHeap;
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