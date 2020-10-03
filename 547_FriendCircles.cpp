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
    int findCircleNum(vector<vector<int>>& M) {
        UnionFindSet s(M.size());
        
        for (int j = 0; j < M.size(); ++j) {
            for (int i = 0; i < M[0].size(); ++i) {
                if (M[j][i] == 1)
                    s.Union(j, i);
            }
        }
        
        unordered_set<int> circle;
        for (int i = 0; i < M.size(); ++i) {
            circle.insert(s.Find(i));
        }
        
        return circle.size();
    }
};

// Disjoint Set
// Runtime: 48 ms, faster than 85.20% of C++ online submissions for Friend Circles.
// Memory Usage: 14.1 MB, less than 30.56% of C++ online submissions for Friend Circles.

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        const int N = M.size();
        vector<bool> visited(N, false);
    
        int ans = 0;
        for(int j = 0; j < N; j++) {
            if (!visited[j]) {
                ans++;
                dfs(M, visited, j);
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>> &M, vector<bool> &visited, int j) {
        for(int i = 0; i < M.size(); ++i) {
            if (M[j][i] == 1 && !visited[i]) {
                visited[i] = true;
                dfs(M, visited, i);
            }
        }
    }
};

// DFS
// Runtime: 40 ms, faster than 99.08% of C++ online submissions for Friend Circles.
// Memory Usage: 13.9 MB, less than 71.08% of C++ online submissions for Friend Circles.

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int ans = 0;
        vector<bool> visited(M.size(), false);
        for(int j = 0; j < M.size(); j++) {
            if (!visited[j]) {
                visited[j] = true;
                ans++;
                dfs(M, visited, j);
            }

        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int j) {
        for(int i = 0; i < M.size(); i++) {
            if (M[j][i] == 1 && !visited[i]) {
                visited[i] = true;
                dfs(M, visited, i);
            }
        }
    }
};

// Runtime: 16 ms, faster than 96.99% of C++ online submissions for Friend Circles.
// Memory Usage: 10.8 MB, less than 100.00% of C++ online submissions for Friend Circles.