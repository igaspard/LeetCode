class Solution {
   public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        return nSumTarget(nums, 4, 0, target);
    }

   private:
    vector<vector<int>> nSumTarget(vector<int> &nums, int n, int start, int target) {
        const int N = nums.size();

        vector<vector<int>> ans;
        if (n < 2 || N < n) return ans;  // min 2 && size should at least n

        if (n == 2) {  // 2 sum sorted
            int low = start, hi = N - 1;
            while (low < hi) {
                int left = nums[low], right = nums[hi];
                int sum = left + right;

                if (sum < target) {  // move low up
                    while (low < hi && nums[low] == left) ++low;
                } else if (sum > target) {  // move hi down
                    while (low < hi && nums[hi] == right) --hi;
                } else if (sum == target) {
                    ans.push_back({left, right});
                    while (low < hi && nums[low] == left) ++low;
                    while (low < hi && nums[hi] == right) --hi;
                }
            }
        } else {  // n > 2, recursive call n - 1 sum
            for (int i = start; i < N; ++i) {
                vector<vector<int>> sub = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
                for (auto s : sub) {
                    s.push_back(nums[i]);
                    ans.push_back(s);
                }
                while (i < N - 1 && nums[i] == nums[i + 1]) ++i;
            }
        }

        return ans;
    }
};

// general solution for n sum problems, when n = 2 using two pointer, n > 2 call n - 1 recursively
// time complexity: O(N^3)
// Runtime: 68 ms, faster than 57.34% of C++ online submissions for 4Sum.
// Memory Usage: 13.6 MB, less than 30.23% of C++ online submissions for 4Sum.

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        if (nums.size() < 4) return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i == 0 || nums[i - 1] != nums[i]) threeSum(nums, i, target, ans);
        }
        return ans;
    }

   private:
    void threeSum(vector<int> &nums, int idx, int target, vector<vector<int>> &ans) {
        for (int i = idx + 1; i < nums.size() - 2; ++i) {
            if (i == idx + 1 || nums[i - 1] != nums[i]) twoSum(nums, idx, i, target, ans);
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
                while (i < j && nums[i] == nums[i - 1]) ++i;
            }
        }
    }
};

// Time complexity: O(N^3)
// Space complexity: O(N)
// Runtime: 84 ms, faster than 46.12% of C++ online submissions for 4Sum.
// Memory Usage: 13.2 MB, less than 58.83% of C++ online submissions for 4Sum.