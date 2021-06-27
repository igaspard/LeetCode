class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        const int N = nums.size();
        int i = 1;
        for (i = 1; i < N; ++i) {
            if (nums[i] <= nums[i-1]) break;
        }
        if (i == N && nums[N-1] > nums[N-2]) return true;

        // try remove i - 1, i
        vector<int> removed = nums;
        vector<int> removed_1 = nums;

        bool ans = true; 
        removed.erase(removed.begin()+i);
        for (i = 1; i < removed.size(); ++i) {
            if (removed[i] <= removed[i-1]) {
                ans = false;
                break;
            }
        }

        if (ans) return ans;

        ans = true;
        removed_1.erase(removed_1.begin() + i - 1);
        for (i = 1; i < removed_1.size(); ++i) {
            if (removed_1[i] <= removed_1[i-1]) {
                ans = false;
                break;
            }
        }

        return ans;
    }
};

// Runtime: 4 ms, faster than 75.00% of C++ online submissions for Remove One Element to Make the Array Strictly Increasing.
// Memory Usage: 10.3 MB, less than 50.00% of C++ online submissions for Remove One Element to Make the Array Strictly Increasing.
