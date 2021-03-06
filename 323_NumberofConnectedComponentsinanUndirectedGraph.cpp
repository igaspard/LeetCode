class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // build up Adjacency lists
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        
        for (auto edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                ++ans;
                dfs(adj, visited, i);
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>> adj, unordered_set<int> &visited, int idx) {
        if (visited[idx]) return;
        
        visited[idx] = true;
        
        for(int i = 0; i < adj[idx].size(); ++i)
            dfs(adj, visited, adj[idx][i]);
    }
};

// Graph
// DFS


class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<bool> visited(n, false);
        vector< vector<int> > adj(n, vector<int>(0));
        stack<int> s;
        
        for(auto edge: edges) {
            adj[edge.first].emplace_back(edge.second);
            adj[edge.second].emplace_back(edge.first);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                ans++;
                s.push(i);
                
                while(!s.empty()) {
                    int cur = s.top(); s.pop();
                    visited[cur] = true;
                    
                    for(auto neighbor: adj[cur]) {
                    if (!visited[neighbor])
                        s.push(neighbor);
                    }
                }    
            }
        }
        return ans;
    }
};

// BFS

