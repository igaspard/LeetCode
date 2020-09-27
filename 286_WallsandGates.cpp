class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for(int j = 0; j < rooms.size(); ++j) {
            for(int i = 0; i < rooms[0].size(); ++i) {
                if (rooms[j][i] == 0)
                    dfs(rooms, j, i, 0);
            }
        }
    }
    
    void dfs(vector<vector<int>> &rooms, int y, int x, int distance) {
        if(x < 0 || x >= rooms[0].size() || y < 0 || y >= rooms.size() || rooms[y][x] < distance)
            return;
        
        rooms[y][x] = distance;
        
        dfs(rooms, y+1, x, distance + 1);
        dfs(rooms, y-1, x, distance + 1);
        dfs(rooms, y, x+1, distance + 1);
        dfs(rooms, y, x-1, distance + 1);
    }
};

// DFS
// Time complexity: O(M*N)
// Space complexity: O(1)
// Runtime: 56 ms, faster than 96.56% of C++ online submissions for Walls and Gates.
// Memory Usage: 14.2 MB, less than 93.02% of C++ online submissions for Walls and Gates.