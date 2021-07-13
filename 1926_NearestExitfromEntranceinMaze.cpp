class Solution {
   public:
    const vector<pair<int, int>> directs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int M = maze.size();
        const int N = maze[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int ans = -1;
        while (!q.empty()) {
            int size = q.size();
            ++ans;
            // cout << "size: " << size << endl;
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                // cout << "cur: " << cur.first << " " << cur.second << endl;
                if (!(cur.first == entrance[0] && cur.second == entrance[1]) && isExit(M, N, cur)) return ans;
                for (auto d : directs) {
                    int y = d.first + cur.first;
                    int x = d.second + cur.second;
                    if (y >= 0 && y < M && x >= 0 && x < N && maze[y][x] == '.') {
                        // cout << "find path " << y << " " << x << " " << endl;
                        q.push({y, x});
                        maze[y][x] = '+';
                    }
                }
            }
        }

        return -1;
    }

   private:
    bool isExit(const int M, const int N, pair<int, int> pos) {
        if (pos.first == 0 || pos.first == M - 1 || pos.second == 0 || pos.second == N - 1) return true;
        return false;
    }
};

// bfs
// Runtime: 204 ms, faster than 20.00% of C++ online submissions for Nearest Exit from Entrance in Maze.
// Memory Usage: 29.7 MB, less than 20.00% of C++ online submissions for Nearest Exit from Entrance in Maze.
