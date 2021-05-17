class Solution {
   public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        const int N = candidates.size();
        vector<bool> visited(N, false);
        vector<int> track;
        backtrack(target, candidates, visited, track, 0);
        return ans;
    }

    void backtrack(int target, const vector<int>& candidates, vector<bool>& visited, vector<int>& track,
                   int start) {
        if (target == 0) {
            ans.emplace_back(track);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (visited[i]) continue;

            if (i > 0 && candidates[i] == candidates[i - 1] && visited[i - 1] == false) continue;

            if (target >= candidates[i]) {
                track.emplace_back(candidates[i]);
                visited[i] = true;
                backtrack(target - candidates[i], candidates, visited, track, i);
                track.pop_back();
                visited[i] = false;
            }
        }
    }
};

// backtrack
