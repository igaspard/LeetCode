class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto it = intervals.begin();
        for(int i = 0; i < intervals.size(); ++i) {
            if(newInterval[0] > intervals[i][0])
                it++;
            else
                break;
        }
        intervals.insert(it, newInterval);
        
        vector<vector<int>> ans;
        for(const auto interval: intervals) {
            if(ans.empty() || interval[0] > ans.back()[1])
                ans.emplace_back(interval);
            else
                ans.back()[1] = max(interval[1], ans.back()[1]);
        }
        
        return ans;
    }
};

// Find the position of the new interval, insert it into the list and call MergeIntervals in LeetCode 56
// Runtime: 28 ms, faster than 87.36% of C++ online submissions for Insert Interval.
// Memory Usage: 17.4 MB, less than 21.17% of C++ online submissions for Insert Interval.