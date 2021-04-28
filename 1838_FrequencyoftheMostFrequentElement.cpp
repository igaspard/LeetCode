class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int ans = 1;
        int l = 0;
        long sum = 0;
        for (int r = 0; r < nums.size(); ++r) {
          sum += nums[r];      
          while (l < r && sum + k < static_cast<long>(nums[r]) * (r - l + 1))
            sum -= nums[l++];
          ans = max(ans, r - l + 1);
        }
         
        return ans;
    }
};

// sliding window
// Runtime: 156 ms, faster than 76.92% of C++ online submissions for Frequency of the Most Frequent Element.
// Memory Usage: 79.3 MB, less than 7.69% of C++ online submissions for Frequency of the Most Frequent Element.

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int ans = 1;
        for (int i = nums.size()-1; i > 0; --i) {
            int target = nums[i];
            int tmp = k, freq = 1;
            for (int j = i-1; j >= 0; --j) {
                if (target-nums[j] <= tmp) {
                    ++freq;
                    tmp -= target - nums[j];
                }
                
                if (!tmp) 
                    break;
            }
            ans = max(ans, freq);
        }
        
        return ans;
    }
};

// Greedy
// Time Limit Exceeded