class Solution {
   public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees) {
        const int N = passingFees.size();

        vector<bool> visited(N, false);
        vector<vector<pair<int, int>>> adj(N);
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> path(N);
        int idx = 0, time = 0;
        vector<int> ans;
        dfs(0, N - 1, adj, visited, path, idx, passingFees, ans, time, maxTime);

        return ans.empty() ? -1 : *min_element(ans.begin(), ans.end());
    }

   private:
    void dfs(int s, int d, vector<vector<pair<int, int>>> &adj, vector<bool> &visited, vector<int> &path,
             int &idx, vector<int> &passingFees, vector<int> &ans, int time, int maxTime) {
        visited[s] = true;
        path[idx] = s;
        ++idx;

        if (s == d) {
            // for (auto p : path) cout << p << " ";
            if (time <= maxTime) {
                int fees = 0;
                for (int i = 0; i < idx; ++i) {
                    // cout << path[i] << " ";
                    fees += passingFees[path[i]];
                }
                ans.emplace_back(fees);
            }
        } else {
            for (auto v : adj[s]) {
                if (!visited[v.first])
                    dfs(v.first, d, adj, visited, path, idx, passingFees, ans, time + v.second, maxTime);
            }
        }

        --idx;
        visited[s] = false;
    }
};

// TLE