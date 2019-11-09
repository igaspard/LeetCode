class Solution {
public:
    vector< vector<bool> > visited;

    void bfs(int i, int j, vector< vector<char> > &grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue< pair<int, int> > q;
        q.push(make_pair(i, j));
        grid[i][j] = 'V';

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int x = cur.first, y = cur.second;

            // check adj
            if (x!=0 && grid[x-1][y] == '1') { // left
                q.push(make_pair(x-1, y));
                grid[x-1][y] = 'V';
            }
            if (x!=m-1 && grid[x+1][y] == '1') { // right
                q.push(make_pair(x+1, y));
                grid[x+1][y] = 'V';
            }
            if (y!=0 && grid[x][y-1] == '1') { // up
                q.push(make_pair(x, y-1));
                grid[x][y-1] = 'V';
            }
            if (y!=n-1 && grid[x][y+1] == '1') { // down
                q.push(make_pair(x, y+1));
                grid[x][y+1] = 'V';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();

        int num = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    bfs(i, j, grid);
                    num++;
                }
            }
        }

        return num;
    }
};
