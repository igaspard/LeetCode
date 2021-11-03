class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) { return threeSumTarget(nums, 0); }

   private:
    vector<vector<int>> twoSumTarget(vector<int>& nums, int start, int target) {
        int i = start, j = nums.size() - 1;

        vector<vector<int>> ans;
        while (i < j) {
            int left = nums[i], right = nums[j];
            int sum = left + right;
            if (sum < target) {
                while (i < j && nums[i] == left) ++i;
            } else if (sum > target) {
                while (i < j && nums[j] == right) --j;
            } else {
                ans.push_back({left, right});
                while (i < j && nums[i] == left) ++i;
                while (i < j && nums[j] == right) --j;
            }
        }

        return ans;
    }

    vector<vector<int>> threeSumTarget(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            vector<vector<int>> tuples = twoSumTarget(nums, i + 1, target - nums[i]);
            for (auto tuple : tuples) {
                tuple.push_back(nums[i]);
                ans.push_back(tuple);
            }

            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
        }

        return ans;
    }
};


// Runtime: 92 ms, faster than 66.59% of C++ online submissions for 3Sum.
// Memory Usage: 26.2 MB, less than 18.99% of C++ online submissions for 3Sum.

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
            if (i == 0 || nums[i - 1] != nums[i]) twoSumII(nums, i, ans);
        }

        return ans;
    }

   private:
    void twoSumII(vector<int>& nums, int idx, vector<vector<int>>& res) {
        int i = idx + 1, j = nums.size() - 1;
        while (i < j) {
            int sum = nums[idx] + nums[i] + nums[j];
            if (sum < 0)
                ++i;
            else if (sum > 0)
                --j;
            else {
                res.push_back({nums[idx], nums[i++], nums[j--]});
                while (i < j && nums[i] == nums[i - 1]) ++i;
            }
        }
    }
};

// Using twosumII and sort first, skip duplicates
// Time Complexity: O(N^2)
// Space Complexity: O(logN) ~ O(N)
// Runtime: 64 ms, faster than 98.02% of C++ online submissions for 3Sum.
// Memory Usage: 19.9 MB, less than 61.61% of C++ online submissions for 3Sum.

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answers;

        if (nums.size() < 3) return answers;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int target = -nums[i];
            int f = i + 1;
            int b = nums.size() - 1;

            while (f < b) {
                int sum = nums[f] + nums[b];

                if (sum < target)
                    f++;
                else if (sum > target)
                    b--;
                else {
                    vector<int> answer{nums[i], nums[f], nums[b]};
                    answers.push_back(answer);

                    while (f < b && nums[f] == answer[1]) f++;
                    while (f < b && nums[b] == answer[2]) b--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return answers;
    }
};