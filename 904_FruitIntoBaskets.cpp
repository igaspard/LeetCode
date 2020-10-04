class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int ans = 0, start = 0;
        unordered_map<int, int> hash;
        for (int end = 0; end < tree.size(); ++end) {
            hash[tree[end]]++;
                
            while (hash.size() > 2) {
                int left = tree[start];
                hash[left]--;
                if (!hash[left]) hash.erase(left);
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};

// Sliding window & Hash Table
// Runtime: 376 ms, faster than 32.08% of C++ online submissions for Fruit Into Baskets.
// Memory Usage: 61.9 MB, less than 31.69% of C++ online submissions for Fruit Into Baskets.