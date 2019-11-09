class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        const int n = nums.size();
        vector<int> f(n, 1);
        vector<int> c(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if (f[j]+1 > f[i]) {
                        f[i] = f[j] + 1;
                        c[i] = c[j];
                    }
                    else if (f[j]+1 == f[i])
                        c[i] += c[j];
                }
            }
        }
        
        int target = *max_element(f.begin(), f.end());
        cout << "target: " << target << endl;
        int ans = 0;
        for(int i = n-1; i >= 0; i--) {
            if(f[i]==target)
                ans += c[i];
        }
        return ans;
    }
};

Runtime: 44 ms, faster than 38.93% of C++ online submissions for Number of Longest Increasing Subsequence.
Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Number of Longest Increasing Subsequence.