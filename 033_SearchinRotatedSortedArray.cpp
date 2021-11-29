class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            
            if (nums[mid] < nums[right]) { // right side sorted
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            } else { // left side sorted
                if (target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int comparator;
            // whether the target & nums[mid] are on the same side
            if ((target < nums[0] && nums[mid] < nums[0]) || 
                (target >= nums[0] && nums[mid] >= nums[0])) {
                comparator = nums[mid];
            } else {
                if (target < nums[0]) comparator = INT_MIN;
                else comparator = INT_MAX;
            }
            
            if (comparator == target) return mid;
            else if (comparator > target) right = mid - 1;
            else if (comparator < target) left = mid + 1;
        }
        
        return -1;
    }
};

// binary search with modifying the value of nums into INF/-INF
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Search in Rotated Sorted Array.
// Memory Usage: 11.1 MB, less than 74.49% of C++ online submissions for Search in Rotated Sorted Array.