class Solution {
   public:
    long long numberOfWeeks(vector<int>& milestones) {
        int mx = *max_element(milestones.begin(), milestones.end());
        long long sum = accumulate(milestones.begin(), milestones.end(), 0ll);
        long long rest = sum - mx;

        return min(sum, rest * 2 + 1);
    }
};

// Runtime: 124 ms, faster than 83.33% of C++ online submissions for Maximum Number of Weeks for Which You Can
// Work. Memory Usage: 75.6 MB, less than 33.33% of C++ online submissions for Maximum Number of Weeks for
// Which You Can Work.