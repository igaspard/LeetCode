class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target)
                return {i+1 , j+1};
            else if (sum < target)
                ++i;
            else
                --j;
        }
        
        return {};
    }
};

// Two pointers
// Time complexity: O(N)
// Space complexity: O(1)
// Runtime: 12 ms, faster than 64.97% of C++ online submissions for Two Sum II - Input array is sorted.
// Memory Usage: 9.8 MB, less than 47.36% of C++ online submissions for Two Sum II - Input array is sorted.