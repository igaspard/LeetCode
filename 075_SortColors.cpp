class Solution {
   public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto n : nums) ++freq[n];

        int idx = 0;
        for (int i = 0; i < 3; ++i) {
            int cnt = freq[i];
            while (cnt-- > 0) nums[idx++] = i;
        }
    }
};

// counting sort
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
// Memory Usage: 8.1 MB, less than 91.24% of C++ online submissions for Sort Colors.

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid = 0;

        while (mid <= high) {
            if (nums[mid] == 0)
                swap(nums[mid++], nums[low++]);
            else if (nums[mid] == 2)
                swap(nums[mid], nums[high--]);
            else
                ++mid;
        }
    }
};

// Two pointers, use low, high to divide into three group, 0, low, 1, high 2
// Runtime: 4 ms, faster than 58.20% of C++ online submissions for Sort Colors.
// Memory Usage: 8.6 MB, less than 9.25% of C++ online submissions for Sort Colors.