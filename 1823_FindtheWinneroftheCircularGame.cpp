class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; ++i)
            nums.emplace_back(i);

        int idx = 0;
        while (nums.size() > 1) {
            int target = (idx + k - 1) % nums.size();
            nums.erase(nums.begin()+target);
            idx = target;
        }

        return nums[0];
    }
};

// Runtime: 4 ms, faster than 60.00% of C++ online submissions for Find the Winner of the Circular Game.
// Memory Usage: 6.3 MB, less than 40.00% of C++ online submissions for Find the Winner of the Circular Game.