class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        
        std::sort(intervals.begin(), intervals.end(),
            [](const vector<int>&a, const vector<int>&b) {
                return a[0] < b[0];
            });
        
        vector<vector<int>> ans;
        for (auto interval: intervals) {
            if(ans.empty() || interval[0] > ans.back()[1])
                ans.emplace_back(interval);
            else
                ans.back()[1] = max(interval[1], ans.back()[1]);
        }
        
        return ans;
    }
};

// sorting and merg intervals
// Time complexity: O(NlogN)
// Space complexity: O(1)
// Runtime: 36 ms, faster than 94.56% of C++ online submissions for Merge Intervals.
// Memory Usage: 14.9 MB, less than 34.06% of C++ online submissions for Merge Intervals.