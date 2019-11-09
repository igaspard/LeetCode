class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        const int n = nums.size();
        auto f = vector<int>(n, 1);
        
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    f[i] = max(f[i], f[j]+1);
            
        return *max_element(f.begin(), f.end());            
    }
};

// Runtime: 48 ms, faster than 15.48% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 8.6 MB, less than 90.63% of C++ online submissions for Longest Increasing Subsequence.

// O(n^2), S = (n)