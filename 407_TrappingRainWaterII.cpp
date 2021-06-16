class Solution {
   public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int M = heightMap.size();
        const int N = heightMap[0].size();

        if (M < 3 || N < 3) return 0;

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;
        // push the boarders into the heap first
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (j == 0 || j == M - 1 || i == 0 || i == N - 1) {
                    minHeap.push({heightMap[j][i], j, i});
                    heightMap[j][i] = -1;  // -1 as visited
                }
            }
        }

        const vector<pair<int, int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ans = 0, level = 0;
        while (!minHeap.empty()) {
            auto [h, y, x] = minHeap.top();
            minHeap.pop();
            level = max(h, level);

            for (auto dir : directs) {
                int Y = y + dir.first;
                int X = x + dir.second;
                if (Y >= 0 && Y < M && X >= 0 && X < N && heightMap[Y][X] != -1) {
                    minHeap.push({heightMap[Y][X], Y, X});
                    if (heightMap[Y][X] < level) ans += level - heightMap[Y][X];
                    heightMap[Y][X] = -1;
                }
            }
        }

        return ans;
    }
};

// heap priority_queue BFS
// Runtime: 80 ms, faster than 56.42% of C++ online submissions for Trapping Rain Water II.
// Memory Usage: 13.1 MB, less than 89.07% of C++ online submissions for Trapping Rain Water II.
