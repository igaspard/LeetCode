class Solution {
   public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans = 0;

        if (rungs[0] > dist) {
            int step = (rungs[0] - 1) / dist;
            ans += step;
        }

        for (int i = 1; i < rungs.size(); ++i) {
            if (rungs[i] - rungs[i - 1] > dist) {
                int step = (rungs[i] - rungs[i - 1] - 1) / dist;
                ans += step;
            }
        }

        return ans;
    }
};

// Runtime: 100 ms, faster than 33.33% of C++ online submissions for Add Minimum Number of Rungs.
// Memory Usage: 54.2 MB, less than 33.33% of C++ online submissions for Add Minimum Number of Rungs.