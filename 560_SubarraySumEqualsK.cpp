class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        unordered_map<int, int> count = {{0, 1}};
        int cur_sum = 0;
        int ans = 0;
        for(auto num: nums) {
            cur_sum += num;
            ans += count[cur_sum - k];
            ++count[cur_sum];
        }
        
        return ans;
    }
};

// PrefixSum + HashTable
// Keep tracking the prefix sums and their counts.
// s -> count: how many arrays nums[0:j] (j < i) that has sum of s
// cur_sum = sum(nums[0:i])
// check how many arrays nums[0:j] (j < i) that has sum (cur_sum – k)
// then there are the same number of arrays nums[j+1: i] that have sum k.
// Time complexity: O(n)
// Space complexity: O(n)
// Runtime: 96 ms, faster than 62.31% of C++ online submissions for Subarray Sum Equals K.
// Memory Usage: 26.8 MB, less than 18.34% of C++ online submissions for Subarray Sum Equals K.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            int prefixSum = 0;
            for(int j = i; j < N; ++j) {
                prefixSum += nums[j];
                if(prefixSum == k) ans++;
            }
        }
            
        return ans;
    }
};

// PrefixSum
// Time complexity: O(N^2)
// Runtime: 1256 ms, faster than 5.00% of C++ online submissions for Subarray Sum Equals K.
// Memory Usage: 16.3 MB, less than 96.62% of C++ online submissions for Subarray Sum Equals K.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<int> prefixSum(N+1, 0);
        
        for(int i = 1; i <= N; ++i)
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        
        int ans = 0;
        for(int i = 0; i < N; ++i)
            for(int j = i; j < N; ++j)
                if(prefixSum[j+1]-prefixSum[i] == k) ans++;
        
        return ans;
    }
};

// prefixSum[i] = sum(nums[0:i-1])
// check each pair(i, j) prefixSum[j+1] - prefixSum[i]  equal to k and count it
// TLE