class Solution {
   public:
    typedef pair<int, int> pii;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> graph(n + 1);
        for (auto t : times) graph[t[0]].emplace_back(t[1], t[2]);

        vector<int> dist(n + 1, INT_MAX);
        dist[0] = 0;
        dist[k] = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.emplace(0, k);  // w, v -> put w in first let pq pop the min weights
        int u, v, w;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            u = cur.second;
            for (auto adj : graph[u]) {
                v = adj.first;
                w = adj.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};

// Dijkstra's algo
// Time complexity: O(NlogN + E)
// Space complexity: O(N+E) graph E, dist array N
// Runtime: 124 ms, faster than 51.86% of C++ online submissions for Network Delay Time.
// Memory Usage: 43.8 MB, less than 23.53% of C++ online submissions for Network Delay Time.