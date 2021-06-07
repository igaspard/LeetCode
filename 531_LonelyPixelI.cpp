class Solution {
   public:
    const vector<pair<int, int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int findLonelyPixel(vector<vector<char>>& picture) {
        M = picture.size();
        N = picture[0].size();
        vector<pair<int, int>> black_pixels;
        for (int j = 0; j < M; ++j)
            for (int i = 0; i < N; ++i)
                if (picture[j][i] == 'B') black_pixels.push_back({j, i});

        int ans = 0;
        for (auto b : black_pixels) {
            bool is_lonely = true;
            for (auto d : directs) is_lonely &= dfs(picture, b.first + d.first, b.second + d.second, d);

            ans += is_lonely ? 1 : 0;
        }
        return ans;
    }

    bool dfs(vector<vector<char>>& picture, int y, int x, pair<int, int> direct) {
        if (y < 0 || y >= M || x < 0 || x >= N) return true;

        if (picture[y][x] == 'B') return false;

        return dfs(picture, y + direct.first, x + direct.second, direct);
    }

   private:
    int M;
    int N;
};

// DFS
// Runtime: 80 ms, faster than 12.92% of C++ online submissions for Lonely Pixel I.
// Memory Usage: 17.7 MB, less than 5.68% of C++ online submissions for Lonely Pixel I.
