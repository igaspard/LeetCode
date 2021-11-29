class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto pre : prerequisites) {
            graph[pre[0]].emplace_back(pre[1]);
            ++inDegree[pre[1]];
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

        return sortedCourses.size() == numCourses;
    }
};

// Topological Sort BFS
// Time Complexity : O(V+E)
// Space complexity: O(V+E)
// Runtime: 24 ms, faster than 52.11% of C++ online submissions for Course Schedule.
// Memory Usage: 14.1 MB, less than 46.19% of C++ online submissions for Course Schedule.

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto edge : prerequisites) graph[edge[0]].emplace_back(edge[1]);

        vector<bool> visited(numCourses, false), path(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i] && !acyclic(graph, visited, path, i)) {
                return false;
            }
        }
        return true;
    }

   private:
    bool acyclic(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &path, int node) {
        if (path[node]) return false;

        if (visited[node]) return true;

        visited[node] = true;
        path[node] = true;
        ;
        for (auto v : graph[node]) {
            if (acyclic(graph, visited, path, v) == false) {
                return false;
            }
        }
        path[node] = false;

        return true;
    }
};

// dfs
// Runtime: 24 ms, faster than 52.11% of C++ online submissions for Course Schedule.
// Memory Usage: 14.4 MB, less than 39.70% of C++ online submissions for Course Schedule.
class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
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

// Topological Sort BFS
// Time Complexity : O(V+E)
// Space complexity: O(V+E)
// Runtime: 28 ms, faster than 26.22% of C++ online submissions for Course Schedule.
// Memory Usage: 15.4 MB, less than 19.05% of C++ online submissions for Course Schedule.
