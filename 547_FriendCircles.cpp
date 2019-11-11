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