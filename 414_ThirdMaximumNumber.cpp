class Solution {
   public:
    int thirdMax(vector<int>& nums) {
        long max1 = numeric_limits<long>::min();
        long max2 = numeric_limits<long>::min();
        long max3 = numeric_limits<long>::min();
        for (auto num : nums) {
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2 && num != max1) {
                max3 = max2;
                max2 = num;
            } else if (num > max3 && num != max1 && num != max2) {
                max3 = num;
            }
        }

        return max3 == numeric_limits<long>::min() ? max1 : max3;
    }
};

// Runtime: 4 ms, faster than 93.38% of C++ online submissions for Third Maximum Number.
// Memory Usage: 9 MB, less than 80.25% of C++ online submissions for Third Maximum Number.
