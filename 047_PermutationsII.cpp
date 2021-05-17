class Solution {
   public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        const int N = nums.size();
        vector<bool> used(N, false);
        vector<int> track;
        backtrack(nums, used, track);
        return ans;
    }

    void backtrack(const vector<int> &nums, vector<bool> &used, vector<int> &track) {
        if (track.size() == nums.size()) {
            ans.emplace_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;

            track.emplace_back(nums[i]);
            used[i] = true;

            backtrack(nums, used, track);

            track.pop_back();
            used[i] = false;
        }
    }
};

// backtrack
// Runtime: 4 ms, faster than 92.68% of C++ online submissions for Permutations II.
// Memory Usage: 9 MB, less than 68.56% of C++ online submissions for Permutations II.
