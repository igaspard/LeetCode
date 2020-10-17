class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int, int>> toSort;
        for (int i = 0; i < points.size(); ++i)
            toSort.emplace_back(points[i][0]*points[i][0]+points[i][1]*points[i][1], i);

        sort(toSort.begin(), toSort.end());
        
        vector<vector<int>> ans;
        for (int i = 0; i < K; ++i)
            ans.emplace_back(points[toSort[i].second]);
        
        return ans;
    }
};

// sort
// Time complexity: O(nlogn)
// Space complexity: O(n)
// Runtime: 284 ms, faster than 93.90% of C++ online submissions for K Closest Points to Origin.
// Memory Usage: 55.3 MB, less than 5.73% of C++ online submissions for K Closest Points to Origin.

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < points.size(); ++i) {
            maxHeap.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
            if (maxHeap.size() > K) maxHeap.pop();
        }

        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            ans.emplace_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }

        return ans;
    }
};

// Heaps
// Time complexity: O(nlogk)
// Space complexity: O(k)
// Runtime: 368 ms, faster than 75.38% of C++ online submissions for K Closest Points to Origin.
// Memory Usage: 53.8 MB, less than 5.73% of C++ online submissions for K Closest Points to Origin.