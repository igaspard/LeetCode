class Solution {
   public:
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        N = graph.size();
        vector<int> path;
        traverse(graph, 0, path);
        return ans;
    }

   private:
    int N;

    void traverse(vector<vector<int>> &graph, int node, vector<int> &path) {
        path.emplace_back(node);

        if (node == N - 1) {
            ans.emplace_back(path);
            path.pop_back();
            return;
        }

        for (auto v : graph[node]) traverse(graph, v, path);

        path.pop_back();
    }
};

// backtracking for graph traverse
// Runtime: 18 ms, faster than 54.30% of C++ online submissions for All Paths From Source to Target.
// Memory Usage: 12.1 MB, less than 56.31% of C++ online submissions for All Paths From Source to Target.
