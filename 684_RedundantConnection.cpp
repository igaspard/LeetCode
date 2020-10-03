class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            unordered_set<int> visited;
            if(dfs(u, v, graph, visited))
                return edge;
            
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        
        return {};
    }
    
    bool dfs(int cur, int goal, unordered_map<int, vector<int>> &graph, unordered_set<int> &visited) {
        if (cur == goal) return true;
        visited.insert(cur);
        if (!graph.count(cur) || !graph.count(goal)) return false;
        for (int next: graph[cur]) {
            if(visited.count(next)) continue;
            if (dfs(next, goal, graph, visited)) return true;
        }
        return false;
    }
    
};

// DFS
// Runtime: 52 ms, faster than 7.58% of C++ online submissions for Redundant Connection.
// Memory Usage: 14.1 MB, less than 7.45% of C++ online submissions for Redundant Connection.

class UnionFindSet {
   private:
    vector<int> parents_;
    vector<int> ranks_;

   public:
    UnionFindSet(int n) {
        ranks_ = vector<int>(n + 1, 0);
        parents_ = vector<int>(n + 1, 0);

        for (int i = 0; i < parents_.size(); ++i) parents_[i] = i;
    }

    int Find(int u) {
        // Compress the path during traversal
        if (u != parents_[u]) parents_[u] = Find(parents_[u]);
        return parents_[u];
    }

    // Merge sets that contain u and v.
    // Returns true if merged, false if u and v are already in one set.
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;

        if (ranks_[pv] < ranks_[pu])
            parents_[pv] = pu;
        else if (ranks_[pu] > ranks_[pv])
            parents_[pu] = pv;
        else {
            parents_[pv] = pu;
            ranks_[pu] += 1;
        }
        return true;
    }
};

class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFindSet s(edges.size());

        for (auto edge : edges) {
            if (!s.Union(edge[0], edge[1])) return edge;
        }

        return {};
    }
};

// Union-Find, Disjoint
// Runtime: 16 ms, faster than 49.27% of C++ online submissions for Redundant Connection.
// Memory Usage: 9.4 MB, less than 27.22% of C++ online submissions for Redundant Connection.
