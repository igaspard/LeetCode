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
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2,
                                vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;

        UnionFindSet s(pairs.size() * 2);

        unordered_map<string, int> hash;
        int id = 0;
        for (auto pair : pairs) {
            int u = getIdx(pair[0], hash, true);
            int v = getIdx(pair[1], hash, true);
            s.Union(u, v);
        }

        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            int u = getIdx(words1[i], hash);
            int v = getIdx(words2[i], hash);
            if (u < 0 || v < 0) return false;
            if (s.Find(u) != s.Find(v)) return false;
        }
        return true;
    }

   private:
    int getIdx(const string A, unordered_map<string, int>& hash, bool create = false) {
        auto it = hash.find(A);
        if (it == hash.end()) {
            if (!create) return numeric_limits<int>::min();
            int id = hash.size();
            hash[A] = id;
            return id;
        }

        return it->second;
    }
};

// Disjoint set, union find
// Time complexity: O(pairs + words)
// Runtime: 332 ms, faster than 96.69% of C++ online submissions for Sentence Similarity II.
// Memory Usage: 65.5 MB, less than 53.19% of C++ online submissions for Sentence Similarity II.

class Solution {
   public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2,
                                vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;

        for (auto pair : pairs) {
            graph[pair[0]].insert(pair[1]);
            graph[pair[1]].insert(pair[0]);
        }

        unordered_map<string, int> hash;
        int id = 0;
        for (auto pair : pairs) {
            if (!hash.count(pair[0])) dfs(pair[0], hash, ++id);
            if (!hash.count(pair[1])) dfs(pair[1], hash, ++id);
        }

        for (int i = 0; i < words1.size(); ++i) {
            const int id1 = hash[words1[i]];
            const int id2 = hash[words2[i]];

            if (id1 != id2) return false;
        }
        return true;
    }

   private:
    void dfs(const string A, unordered_map<string, int>& hash, int id) {
        hash[A] = id;

        for (string next : graph[A]) {
            if (hash.count(next)) continue;
            dfs(next, hash, id);
        }
    }
    unordered_map<string, unordered_set<string>> graph;
};

// DFS + Hash table
// Time complexity: O(pairs + words)
// Runtime: 456 ms, faster than 70.45% of C++ online submissions for Sentence Similarity II.
// Memory Usage: 96.6 MB, less than 23.17% of C++ online submissions for Sentence Similarity II.

class Solution {
   public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2,
                                vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;

        unordered_map<string, unordered_set<string>> graph;
        for (auto pair : pairs) {
            graph[pair[0]].insert(pair[1]);
            graph[pair[1]].insert(pair[0]);
        }

        unordered_set<string> visited;
        for (int i = 0; i < words1.size(); ++i) {
            if (!dfs(words1[i], words2[i], graph, visited)) return false;
        }
        return true;
    }

   private:
    bool dfs(const string A, const string B, unordered_map<string, unordered_set<string>> graph,
             unordered_set<string> visited) {
        if (A == B) return true;

        visited.insert(A);
        for (string a : graph[A]) {
            if (visited.count(a)) continue;
            if (dfs(a, B, graph, visited)) return true;
        }

        return false;
    }
};

// DFS
// Time Limit Exceeded
// Time Complexity: O(pairs * words)