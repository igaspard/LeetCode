class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> track;
        int ans = 0;
        backtrack(nums, 0, track, ans);
        return ans;
    }
    
    void backtrack(const vector<int>& nums, int start, vector<int>& track, int &ans) {
        if (!track.empty()) {
            int XOR = track[0];
            for (int i = 1; i < track.size(); ++i) 
                XOR ^= track[i];
            ans += XOR;
        }

        for (int i = start; i < nums.size(); ++i) {
            track.emplace_back(nums[i]);
            backtrack(nums, i + 1, track, ans);
            track.pop_back();
        }
    }
};
// backtrack
// Runtime: 4 ms, faster than 57.14% of C++ online submissions for Sum of All Subset XOR Totals.
// Memory Usage: 7.2 MB, less than 71.43% of C++ online submissions for Sum of All Subset XOR Totals.