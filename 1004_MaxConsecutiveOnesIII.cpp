class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, start = 0, zeroCnt = 0;
        for (int end = 0; end < nums.size(); ++end) {
            if (nums[end] == 0) ++zeroCnt;
            
            while (zeroCnt > k) {
                if (nums[start] == 0) --zeroCnt;
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        
        return ans;
    }
};

// sliding window
// Runtime: 60 ms, faster than 48.39% of C++ online submissions for Max Consecutive Ones III.
// Memory Usage: 55.4 MB, less than 60.21% of C++ online submissions for Max Consecutive Ones III.