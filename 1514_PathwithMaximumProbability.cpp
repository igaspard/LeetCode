class Solution {
   public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        vector<double> prob(n, 0.0);
        prob[start] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start);

        int u, v;
        double p;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            u = cur.second;
            for (auto adj : graph[u]) {
                v = adj.first;
                p = adj.second;

                if (prob[v] < prob[u] * p) {
                    prob[v] = prob[u] * p;
                    pq.emplace(prob[v], v);
                }
            }
        }

        return prob[end];
    }
};

// Dijkstra's algo
// Time complexity: O(NlogN + E)
// Space complexity: O(N+E) graph E, dist array N
// Runtime: 296 ms, faster than 25.28% of C++ online submissions for Path with Maximum Probability.
// Memory Usage: 66.2 MB, less than 60.85% of C++ online submissions for Path with Maximum Probability.