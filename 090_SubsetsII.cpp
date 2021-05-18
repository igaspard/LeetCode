class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        N = nums.size();
        vector<bool> used(N, false);
        vector<int> track;
        
        backtrack(nums, 0, used, track);
        return ans;
    }
    
    void backtrack(const vector<int> &nums, int start, vector<bool> &used, vector<int> &track) {
        ans.emplace_back(track);
        
        for (int i = start; i < N; ++i) {
            if (used[i]) continue;
            
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            
            track.emplace_back(nums[i]);
            used[i] = true;
            
            backtrack(nums, i + 1, used, track);
            
            track.pop_back();
            used[i] = false;
        }
    }

private:
    int N;
};

// backtrack 
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets II.
// Memory Usage: 7.8 MB, less than 55.00% of C++ online submissions for Subsets II.

class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sort the numbers to handle duplicates
        vector<vector<int>> subsets;
        subsets.push_back(vector<int>());
        int startIndex = 0, endIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            startIndex = 0;
            // if current and the previous elements are same, create new subsets only from the subsets
            // added in the previous step
            if (i > 0 && nums[i] == nums[i - 1]) {
                startIndex = endIndex + 1;
            }
            endIndex = subsets.size() - 1;
            for (int j = startIndex; j <= endIndex; j++) {
                // create a new subset from the existing subset and add the current element to it
                vector<int> set(subsets[j]);
                set.push_back(nums[i]);
                subsets.push_back(set);
            }
        }
        return subsets;
    }
};

// Runtime: 4 ms, faster than 85.18% of C++ online submissions for Subsets II.
// Memory Usage: 7.6 MB, less than 87.38% of C++ online submissions for Subsets II.