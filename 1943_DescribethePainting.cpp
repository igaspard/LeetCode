class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> m;
        for (auto seg : segments) {
            m[seg[0]] += seg[2];
            m[seg[1]] -= seg[2];
        }
        
        long long sum = 0, begin = 0;
        vector<vector<long long>> ans;
        for (auto it : m) {
            long long pre = sum;
            sum += it.second;
            long long end = it.first;
            
            if (pre > 0) ans.push_back({begin, end, pre});
            begin = end;
        }
        
        return ans;
    }
};

// reference meeting rooms II 
// Runtime: 432 ms, faster than 16.67% of C++ online submissions for Describe the Painting.
// Memory Usage: 109.1 MB, less than 16.67% of C++ online submissions for Describe the Painting.