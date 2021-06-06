class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(), packages.end());

        long ans = numeric_limits<long>::max(), sum = 0;
        const long MOD = 1e9 + 7;
        for (int p : packages) sum += p;

        for (auto& box : boxes) {
            sort(box.begin(), box.end());
            if (box.back() < packages.back()) continue;
            long wasted = 0, i = 0, j;
            for (auto b : box) {
                j = upper_bound(packages.begin(), packages.end(), b) - packages.begin();
                wasted = wasted + b * (j - i);
                i = j;
            }
            ans = min(wasted, ans);
        }

        return ans < numeric_limits<long>::max() ? (ans - sum) % MOD : -1;
    }
};

// sort + binary search
// Runtime: 284 ms, faster than 100.00% of C++ online submissions for Minimum Space Wasted From Packaging.
// Memory Usage: 110.2 MB, less than 50.00% of C++ online submissions for Minimum Space Wasted From Packaging.
