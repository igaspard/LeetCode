class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i) ans[i] = ans[i & (i - 1)] + 1;

        return ans;
    }
};

// DP + bit manipulation i & (i - 1) turn off the rightest bits and plus 1
// Time complexity: O(N)
// Space complexity: O(N)
// Runtime: 4 ms, faster than 90.92% of C++ online submissions for Counting Bits.
// Memory Usage: 7.8 MB, less than 87.28% of C++ online submissions for Counting Bits.

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i) ans[i] = ans[i >> 1] + (i & 1);

        return ans;
    }
};

// DP + bit manipulation i >> 1 + [0] == 1 or not
// Time complexity: O(N)
// Space complexity: O(N)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Counting Bits.
// Memory Usage: 7.8 MB, less than 70.58% of C++ online submissions for Counting Bits.

class Solution {
   public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for (int i = 0; i <= num; ++i) ans.emplace_back(hammingWeight(i));

        return ans;
    }

   private:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n &= (n - 1);
            ans++;
        }

        return ans;
    }
};

// Runtime: 8 ms, faster than 72.37% of C++ online submissions for Counting Bits.
// Memory Usage: 8.4 MB, less than 39.63% of C++ online submissions for Counting Bits.
