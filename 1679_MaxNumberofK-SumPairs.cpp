class Solution {
   public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;
        int ans = 0;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) {
                ++ans;
                ++i;
                --j;
            } else if (sum < k) {
                ++i;
            } else if (sum > k) {
                --j;
            }
        }

        return ans;
    }
};

// sort + two pointers
// Runtime: 116 ms, faster than 84.77% of C++ online submissions for Max Number of K-Sum Pairs.
// Memory Usage: 58.1 MB, less than 96.63% of C++ online submissions for Max Number of K-Sum Pairs.

class Solution {
   public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> hash;
        ++hash[nums[0]];
        for (int i = 1; i < nums.size(); ++i) {
            int target = k - nums[i];
            if (hash.count(target) != 0) {
                --hash[target];
                if (hash[target] == 0) hash.erase(target);
                ++ans;
            } else {
                ++hash[nums[i]];
            }
        }

        return ans;
    }
};

// Hash
// Runtime: 168 ms, faster than 40.82% of C++ online submissions for Max Number of K-Sum Pairs.
// Memory Usage: 67.9 MB, less than 43.20% of C++ online submissions for Max Number of K-Sum Pairs.
