class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        
        int num1 = 0, overlapped = 0;
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (grid[j][i] == 1) {
                    ++num1;
                    if (j != 0 && grid[j-1][i] == 1) ++overlapped;
                    if (i != 0 && grid[j][i-1] == 1) ++overlapped;
                }
            }
        }
        
        return num1 * 4 - overlapped * 2;
    }
};

// count number of land & overlapped top & left.
// Runtime: 115 ms, faster than 40.52% of C++ online submissions for Island Perimeter.
// Memory Usage: 96.3 MB, less than 58.06% of C++ online submissions for Island Perimeter.

class Solution {
   public:
    const vector<pair<int, int>> directs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();

        int ans = 0;
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (grid[j][i] == 1) {
                    for (auto d : directs) {
                        int y = j + d.first;
                        int x = i + d.second;
                        if (y >= 0 && y < M && x >= 0 && x < N && grid[y][x] == 0) ++ans;
                    }
                    if (j == 0) ++ans;
                    if (j == M - 1) ++ans;
                    if (i == 0) ++ans;
                    if (i == N - 1) ++ans;
                }
            }
        }

        return ans;
    }
};

// Runtime: 167 ms, faster than 22.40% of C++ online submissions for Island Perimeter.
// Memory Usage: 96.4 MB, less than 36.63% of C++ online submissions for Island Perimeter.