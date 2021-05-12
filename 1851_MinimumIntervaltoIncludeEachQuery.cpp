class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(),
         [](const vector<int>& A, const vector<int>& B) { return A[1] - A[0] < B[1] - B[0]; });
        
        const int N = queries.size();
    
        set<pair<int, int>> set;
        for (int i = 0; i < N; ++i)
            set.insert({queries[i], i});

        vector<int> ans(N, -1);
        for (auto interval : intervals) {
            int start = interval[0], end = interval[1];
            auto it = set.lower_bound({start, 0});
            while (it != set.end() && it->first <= end) {
                auto it2 = next(it);
                ans[it->second] = end - start + 1;
                set.erase(it);
                it = it2;
            }
        }

        return ans;
    }
};

// Sort + some trick
// For implementation, I used a set to track queries and after populating each query, I'd remove it from the set as we no longer need to worry about it
// To enhance performance, once I find the lower_bound, I increment the iterator and keep deleting any values that are within the interval.

// Runtime: 576 ms, faster than 71.43% of C++ online submissions for Minimum Interval to Include Each Query.
// Memory Usage: 133 MB, less than 100.00% of C++ online submissions for Minimum Interval to Include Each Query.