class Solution {
   public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        if (nums.size() < 4) return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i == 0 || nums[i-1] != nums[i]) threeSum(nums, i, target, ans);
        }
        return ans;
    }

   private:
    void threeSum(vector<int> &nums, int idx, int target, vector<vector<int>> &ans) {
        for (int i = idx + 1; i < nums.size() - 2; ++i) {
            if (i == idx + 1 || nums[i-1] != nums[i]) twoSum(nums, idx, i, target, ans);
        }
    }

    void twoSum(vector<int> &nums, int pre, int idx, int target, vector<vector<int>> &res) {
        int i = idx + 1, j = nums.size() - 1;
        while (i < j) {
            int sum = nums[pre] + nums[idx] + nums[i] + nums[j];
            if (sum < target)
                ++i;
            else if (sum > target)
                --j;
            else {
                res.push_back({nums[pre], nums[idx], nums[i++], nums[j--]});
                while (i < j && nums[i] == nums[i-1]) ++i;
            }
        }
    }
};

// Time complexity: O(N^3)
// Space complexity: O(N)
// Runtime: 84 ms, faster than 46.12% of C++ online submissions for 4Sum.
// Memory Usage: 13.2 MB, less than 58.83% of C++ online submissions for 4Sum.