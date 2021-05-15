class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> set;
        backtrack(nums, 0, set);
        return ans;
    }

    void backtrack(const vector<int>& nums, int start, vector<int>& set) {
        ans.emplace_back(set);
        for (int i = start; i < nums.size(); ++i) {
            set.emplace_back(nums[i]);
            backtrack(nums, i+1, set);
            set.pop_back();
        }
    }
};

// backtrack
// Time complexity: O(N×2^N)
// Space complexity: O(N)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
// Memory Usage: 7.2 MB, less than 57.72% of C++ online submissions for Subsets.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        
        ans.emplace_back(vector<int>());
        for(auto num: nums) {
            const int N = ans.size();
            
            for(int i = 0; i < N; ++i) {
                vector<int> new_subset(ans[i]);
                new_subset.emplace_back(num);
                ans.emplace_back(new_subset);
            }
        }
        return ans;
    }
};


// Runtime: 4 ms, faster than 71.85% of C++ online submissions for Subsets.
// Memory Usage: 7 MB, less than 91.57% of C++ online submissions for Subsets.
