class Solution {
   public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int M = dungeon.size();
        const int N = dungeon[0].size();

        vector<vector<int>> hp(M + 1, vector<int>(N + 1, INT_MAX));
        hp[M - 1][N] = 1;
        hp[M][N - 1] = 1;

        for (int j = M - 1; j >= 0; --j) {
            for (int i = N - 1; i >= 0; --i) {
                int val = min(hp[j + 1][i], hp[j][i + 1]) - dungeon[j][i];
                hp[j][i] = max(1, val);
            }
        }

        return hp[0][0];
    }
};

// DP
// Runtime: 7 ms, faster than 61.83% of C++ online submissions for Dungeon Game.
// Memory Usage: 9 MB, less than 45.44% of C++ online submissions for Dungeon Game.
