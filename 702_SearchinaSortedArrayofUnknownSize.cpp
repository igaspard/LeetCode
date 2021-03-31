/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = 1;
        
        while (reader.get(right) < target) {
            int new_left = right + 1;
            right += (right - left + 1) * 2;
            left = new_left;
        }
        
        return binary_search(reader, target, left, right);
    }
    
    int binary_search(const ArrayReader& reader, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (reader.get(mid) == target) return mid;
            else if (reader.get(mid) < target) left = mid + 1;
            else if (reader.get(mid) > target) right = mid - 1;
        }
        
        return -1;
    }
};

// Runtime: 24 ms, faster than 97.14% of C++ online submissions for Search in a Sorted Array of Unknown Size.
// Memory Usage: 10 MB, less than 73.79% of C++ online submissions for Search in a Sorted Array of Unknown Size.