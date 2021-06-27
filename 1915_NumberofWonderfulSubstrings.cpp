class Solution {
   public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, long long> freq = {{0, 1}};
        long long mask = 0, ans = 0;
        for (auto c : word) {
            mask ^= 1 << (c - 'a');
            ans += freq[mask];

            for (char ch = 'a'; ch <= 'j'; ++ch) {
                long long target = mask ^ (1 << (ch - 'a'));
                ans += freq[target];
            }

            ++freq[mask];
        }

        return ans;
    }
};

// bitmask + hash
// Runtime: 456 ms, faster than 88.89% of C++ online submissions for Number of Wonderful Substrings.
// Memory Usage: 18.6 MB, less than 22.22% of C++ online submissions for Number of Wonderful Substrings.

class Solution {
   public:
    long long wonderfulSubstrings(string word) {
        const int N = word.length();

        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            unordered_map<char, int> freq;
            int odd_cnt = 0;
            for (int j = i; j < N; ++j) {
                ++freq[word[j]];
                if (freq[word[j]] % 2 == 1)
                    ++odd_cnt;
                else
                    --odd_cnt;

                if (odd_cnt <= 1) ++ans;
            }
        }
        return ans;
    }
};

// brute force, O(N^2)