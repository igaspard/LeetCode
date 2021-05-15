/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> track;
        backtrack(target, candidates, track, 0);
        return ans;
    }

    void backtrack(int target, const vector<int> candidates, vector<int>& track, int start) {
        if (target == 0) {
            ans.emplace_back(track);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                track.emplace_back(candidates[i]);
                backtrack(target - candidates[i], candidates, track, i);
                track.pop_back();
            }
        }
    }
};
// @lc code=end
// backtrack