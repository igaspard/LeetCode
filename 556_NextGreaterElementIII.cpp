class Solution {
   public:
    int nextGreaterElement(int n) {
        deque<int> nums;
        while (n) {
            nums.push_front(n % 10);
            n /= 10;
        }

        while (std::next_permutation(nums.begin(), nums.end())) {
            long next = 0;
            for (auto it : nums) next = next * 10 + it;

            if (next > numeric_limits<int>::max()) return -1;

            if (next > n) return next;
        }

        return -1;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Greater Element III.
// Memory Usage: 6.1 MB, less than 15.13% of C++ online submissions for Next Greater Element III.