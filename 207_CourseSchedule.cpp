class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree;

        for (int i = 0; i < numCourses; ++i) {
            inDegree[i] = 0;
            graph[i] = vector<int>();
        }
        for (auto it : prerequisites) {
            graph[it[0]].emplace_back(it[1]);
            ++inDegree[it[1]];
        }

        queue<int> q;
        for (auto entry : inDegree) {
            if (entry.second == 0) q.push(entry.first);
        }

        vector<int> sortedCourses;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            sortedCourses.emplace_back(it);
            auto children = graph[it];
            for (auto child : children) {
                --inDegree[child];
                if (inDegree[child] == 0) q.push(child);
            }
        }
 
        return sortedCourses.size() == numCourses;
    }
};

// Topological Sort 
// Time Complexity : O(V+E)
// Space complexity: O(V+E)
// Runtime: 28 ms, faster than 26.22% of C++ online submissions for Course Schedule.
// Memory Usage: 15.4 MB, less than 19.05% of C++ online submissions for Course Schedule.

