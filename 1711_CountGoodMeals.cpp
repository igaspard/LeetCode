class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> hash;
        const int MOD = 1e9 + 7;

        int ans = 0;
        for (auto it : deliciousness) {
            for (int i = 0 ; i <= 21; ++i) {
                int target = (1 << i) - it;
                if (hash.find(target) != hash.end()) ans += hash[target];

                ans %= MOD;
            }

            ++hash[it];
        }
            return ans;
    }
};

// Hash, similar to two sum
// Runtime: 412 ms, faster than 62.77% of C++ online submissions for Count Good Meals.
// Memory Usage: 58 MB, less than 67.65% of C++ online submissions for Count Good Meals.
