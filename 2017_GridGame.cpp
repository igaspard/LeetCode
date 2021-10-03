class Solution {
   public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = accumulate(grid[0].begin(), grid[0].end(), 0ll), bottomSum = 0;

        long long ans = LLONG_MAX;
        for (int i = 0; i < grid[0].size(); ++i) {
            topSum -= grid[0][i];
            ans = min(ans, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }

        return ans;
    }
};

// prefix sum
// PS: 1st bots is not maximize his score, it's trying to minimize the 2nd bots scores.
// Here is test cases.
// 10 50 50 30
// 50 50 10 10
// if 1st bot find the max, it 2nd bot can get 110 points.
// 00 00 00 00
// 50 50 10 00
// However, if 1st do like this, 2nd bot only get 110 points.
// 00 00 50 30
// 50 00 00 00
// Runtime: 148 ms, faster than 100.00% of C++ online submissions for Grid Game.
// Memory Usage: 62.8 MB, less than 91.67% of C++ online submissions for Grid Game.
