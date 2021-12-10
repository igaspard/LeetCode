class Solution {
   public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // build graph
        for (auto acc : accounts) {
            for (int i = 1; i < acc.size() - 1; ++i) {
                graph[acc[i]].emplace_back(acc[i + 1]);
                graph[acc[i + 1]].emplace_back(acc[i]);
            }
        }
        // find connected components in graph
        for (auto acc : accounts) {
            if (visited.count(acc[1]) == 0) {
                ans.push_back({acc[0]});
                dfs(acc[1]);
                sort(ans.back().begin() + 1, ans.back().end());
            }
        }

        return ans;
    }

   private:
    unordered_map<string, vector<string>> graph;
    unordered_set<string> visited;
    vector<vector<string>> ans;

    void dfs(string email) {
        visited.insert(email);
        ans.back().emplace_back(email);
        for (auto adj_email : graph[email]) {
            if (visited.count(adj_email) == 0) dfs(adj_email);
        }
    }
};

// Turn email into graph, problem become finding the connected components in undirected graph by dfs
// Runtime: 120 ms, faster than 64.60% of C++ online submissions for Accounts Merge.
// Memory Usage: 50.7 MB, less than 25.54% of C++ online submissions for Accounts Merge.