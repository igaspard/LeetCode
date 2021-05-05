class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int N = nums.size();
        
        stack<int> s;
        vector<int> ans(N);
        for (int i = nums.size()*2-1; i >= 0; --i) {
            while(!s.empty() && nums[i % N] >= s.top())
                s.pop();
            ans[i % N] = s.empty() ? -1 : s.top();
            s.push(nums[i % N]);
        }
        
        return ans;
    }
};

// Monotonic Stack
// Runtime: 24 ms, faster than 95.88% of C++ online submissions for Next Greater Element II.
// Memory Usage: 23.9 MB, less than 63.53% of C++ online submissions for Next Greater Element II.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> double_nums(nums);
        for (auto num : nums)
            double_nums.emplace_back(num);
        
        stack<int> s;
        vector<int> ans(double_nums.size());
        for (int i = double_nums.size()-1; i >= 0; --i) {
            while(!s.empty() && double_nums[i] >= s.top())
                s.pop();
            ans[i] = s.empty() ? -1 : s.top();
            s.push(double_nums[i]);
        }
        
        ans.resize(nums.size());
        return ans;
    }
};

// Monotonic Stack
// Runtime: 36 ms, faster than 42.68% of C++ online submissions for Next Greater Element II.
// Memory Usage: 25.8 MB, less than 9.03% of C++ online submissions for Next Greater Element II.