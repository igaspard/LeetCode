class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto pre : prerequisites) {
            graph[pre[1]].emplace_back(pre[0]);
            ++inDegree[pre[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (inDegree[i] == 0) q.push(i);

        vector<int> sortedCourses;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            sortedCourses.emplace_back(cur);

            for (auto child : graph[cur]) {
                --inDegree[child];
                if (inDegree[child] == 0) q.push(child);
            }
        }

        if (sortedCourses.size() != numCourses) return {};

        return sortedCourses;
    }
};

// Topological Sort BFS
// Time Complexity : O(V+E)
// Space complexity: O(V+E)
// Runtime: 24 ms, faster than 52.98% of C++ online submissions for Course Schedule II.
// Memory Usage: 14.2 MB, less than 47.64% of C++ online submissions for Course Schedule II.
