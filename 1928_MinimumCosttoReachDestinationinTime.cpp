class Solution {
   public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees) {
        const int N = passingFees.size();
        vector<vector<pair<int, int>>> graph(N);  // v, times
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].emplace_back(edges[i][1], edges[i][2]);
            graph[edges[i][1]].emplace_back(edges[i][0], edges[i][2]);
        }

        vector<int> cost(N, INT_MAX);
        cost[0] = passingFees[0];

        vector<int> time(N, INT_MAX);
        time[0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({cost[0], time[0], 0});

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int c = cur[0];
            int t = cur[1];
            int u = cur[2];
            for (auto adj : graph[u]) {
                int v = adj.first;
                int adj_t = adj.second;
                int adj_c = passingFees[v];

                if (t + adj_t <= maxTime) {
                    if (cost[v] > c + adj_c) {
                        cost[v] = c + adj_c;
                        time[v] = t + adj_t;
                        pq.push({cost[v], time[v], v});
                    } else if (time[v] > t + adj_t) {
                        time[v] = t + adj_t;
                        pq.push({c + adj_c, time[v], v});
                    }
                }
            }
        }

        return cost[N - 1] == INT_MAX ? -1 : cost[N - 1];
    }
};

// Dijkstra's algo
// Time complexity: O(NlogN + E)
// Space complexity: O(2*N+E) graph E, cost & time array N
// Runtime: 348 ms, faster than 70.31% of C++ online submissions for Minimum Cost to Reach Destination in
// Time. Memory Usage: 45.1 MB, less than 45.82% of C++ online submissions for Minimum Cost to Reach
// Destination in Time.

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