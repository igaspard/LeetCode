class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree;
        // init
        for (auto seq : seqs) {
            for (int i = 0; i < seq.size(); ++i) {
                graph[seq[i]] = vector<int>();
                inDegree[seq[i]] = 0;
            }
        }
        // build graph
        for (auto seq : seqs) {
            for (int i = 0; i < seq.size()-1; ++i) {
                int src = seq[i];
                int dst = seq[i+1];
                graph[src].emplace_back(dst);
                ++inDegree[dst];
            }
        }
        // output graph & inDegree
        // for (auto vertex : graph) {
        //     cout << vertex.first << " -> ";
        //     for (auto adj : vertex.second) {
        //         cout << adj << " ";
        //     }
        //     cout << ": inDegree " << inDegree[vertex.first] << endl;
        // }
        if (inDegree.size() != org.size()) return false;
        
        queue<int> s;
        for (auto entry : inDegree) {
            if (entry.second == 0) s.push(entry.first);
        }
        vector<int> sortedOrder;
        while (!s.empty()) {
            if (s.size() > 1) return false;
            if (org[sortedOrder.size()] != s.front()) return false;
            auto it = s.front();
            s.pop();
            sortedOrder.emplace_back(it);
            auto children = graph[it];
            for (auto child : children) {
                --inDegree[child];
                if(inDegree[child] == 0) s.push(child);
            }
        }
        // cout << "sortedOrder: ";
        // for (auto it : sortedOrder)
        //     cout << it << " ";
        // cout << endl;
        
        return sortedOrder.size() == org.size();
    }
};

	
};

// Topological Sort
// Time complexity O(V+E)
// Space complexity O(V+E)
// Runtime: 204 ms, faster than 24.29% of C++ online submissions for Sequence Reconstruction.
// Memory Usage: 69.8 MB, less than 39.52% of C++ online submissions for Sequence Reconstruction.
