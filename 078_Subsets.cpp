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


Runtime: 4 ms, faster than 71.85% of C++ online submissions for Subsets.
Memory Usage: 7 MB, less than 91.57% of C++ online submissions for Subsets.