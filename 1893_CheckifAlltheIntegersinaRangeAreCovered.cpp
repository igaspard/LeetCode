class Solution {
   public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for (int i = left; i <= right; ++i) {
            bool found = false;
            for (auto range : ranges) {
                if (range[0] <= i && i <= range[1]) {
                    found = true;
                    break;
                }
            }

            if (!found) return false;
        }

        return true;
    }
};

// Greedy
// Runtime: 12 ms, faster than 16.67% of C++ online submissions for Check if All the Integers in a Range Are
// Covered. Memory Usage: 9.1 MB, less than 16.67% of C++ online submissions for Check if All the Integers in
// a Range Are Covered.