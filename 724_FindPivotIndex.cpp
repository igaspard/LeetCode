class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int N = nums.size();
        if(!N) return -1;
        
        int sum = 0;
        for(auto num: nums)
            sum += num;

        int leftsum = 0;
        for(int i = 0; i < N; ++i) {
            if (leftsum == sum - leftsum - nums[i])
                return i;
            leftsum += nums[i];
        }
        return -1;
    }
};

// Prefix Sum
// Sum = leftSum + n + rightSum -> Sum - n - rightSum == leftSum 
// if (leftSum==RightSum) -> Sum - n - leftSum == leftSum
// Time complexity: O(N)
// Space complexity: O(1)
// Runtime: 44 ms, faster than 89.45% of C++ online submissions for Find Pivot Index.
// Memory Usage: 31.1 MB, less than 72.12% of C++ online submissions for Find Pivot Index.

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int N = nums.size();
        if(!N) return -1;
        vector<int> left(N);
        vector<int> right(N);
        
        left[0] = nums[0];
        for(int i = 1; i < N; ++i)
            left[i] = left[i-1] + nums[i];
        
        right[N-1] = nums[N-1];
        for(int i = N-2; i >= 0; --i)
            right[i] = right[i+1] + nums[i];
        
        int ans = -1;
        for(int i = 0; i < N; ++i) {
            if(left[i] == right[i]) {
                ans = i;
                break;
            }
        }
            
        return ans;
    }
};

// Time Complexity: O(N), Space Compplexity: O(N)
// Runtime: 56 ms, faster than 48.64% of C++ online submissions for Find Pivot Index.
// Memory Usage: 32.1 MB, less than 10.89% of C++ online submissions for Find Pivot Index.