class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty()) return true;
        std::sort(intervals.begin(), intervals.end(),
                 [](const vector<int>&a, const vector<int>&b) {
                     return a[0] < b[0];
                 });
        
        for(int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i][1] > intervals[i+1][0])
                return false;
        }
        
        return true;
    }
};

// interval, sorting and check overlap
// Time complexity: O(NlogN)
// Space complexity: O(1)
// Runtime: 32 ms, faster than 97.87% of C++ online submissions for Meeting Rooms.
// Memory Usage: 12 MB, less than 35.21% of C++ online submissions for Meeting Rooms.