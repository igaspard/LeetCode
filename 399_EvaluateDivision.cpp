class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < equations.size(); ++i) {
            const string A = equations[i][0];
            const string B = equations[i][1];
            double value = values[i];

            graph[A][B] = value;
            graph[B][A] = 1 / value;
        }

        vector<double> ans;
        for (auto query : queries) {
            const string X = query[0];
            const string Y = query[1];

            if (!graph.count(X) || !graph.count(Y))
                ans.emplace_back(-1);
            else {
                unordered_set<string> visited;
                ans.emplace_back(dfs(graph, X, Y, visited));
            }
        }

        return ans;
    }

    double dfs(unordered_map<string, unordered_map<string, double>>& graph, const string X, const string Y,
               unordered_set<string>& visited) {
        if (X == Y) return 1.0;

        visited.insert(X);

        for (auto next : graph[X]) {
            const string Z = next.first;
            if (visited.count(Z)) continue;
            double z = dfs(graph, Z, Y, visited);
            if (z > 0) return graph[X][Z] * z;
        }

        return -1;
    }
};

// DFS
// Runtime: 4 ms, faster than 61.17% of C++ online submissions for Evaluate Division.
// Memory Usage: 8.4 MB, less than 51.94% of C++ online submissions for Evaluate Division.
