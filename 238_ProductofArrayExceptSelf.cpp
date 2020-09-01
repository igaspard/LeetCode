class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        vector<int> ans(N, 1);
        
        int i = 1;
        for(; i < N; ++i)
            ans[i] = ans[i-1] * nums[i-1];
        
        int R = 1;
        i = N - 1;
        for(; i >= 0; --i) {
            ans[i] *= R;
            R *= nums[i];
        }
        
        return ans;
    }
};

// Prefix Sum, left product * right product
// Time complexity: O(N)
// Sum complexity: O(1)
// Runtime: 16 ms, faster than 97.09% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 15.9 MB, less than 64.42% of C++ online submissions for Product of Array Except Self.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        vector<int> left(N, 1);
        vector<int> right(N, 1);
        
        for(int i = 1; i < N; ++i)
            left[i] = left[i-1] * nums[i-1];
        
        for(int i = N-2; i >= 0; --i)
            right[i] = right[i+1] * nums[i+1];
        
        vector<int> ans;
        for(int i = 0; i < N; ++i)
            ans.emplace_back(left[i] * right[i]);
        
        return ans;
    }
};

// Prefix Sum, left product * right product
// Time complexity: O(N)
// Sum complexity: O(N)
// Runtime: 16 ms, faster than 97.09% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 16.7 MB, less than 6.33% of C++ online submissions for Product of Array Except Self.