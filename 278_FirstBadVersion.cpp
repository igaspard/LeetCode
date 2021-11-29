// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) right = mid - 1;
            else left = mid + 1;
        }
        
        return left;
    }
};

// time complexity: O(log n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Bad Version.
// Memory Usage: 5.7 MB, less than 99.65% of C++ online submissions for First Bad Version.