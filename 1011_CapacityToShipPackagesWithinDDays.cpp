class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) right = mid -1;
            else left = mid + 1;
        }
        
        return left;
    }
    
    bool canShip(const vector<int> &weights, const int days, int cap) {
        int day = 1, sum = 0;
        for (auto w : weights) {
            sum += w;
            if (sum > cap) {
                ++day;
                sum = w;
            }
        }
        
        return day <= days;
    }
};

// binary search
// Runtime: 64 ms, faster than 37.12% of C++ online submissions for Capacity To Ship Packages Within D Days.
// Memory Usage: 26 MB, less than 61.59% of C++ online submissions for Capacity To Ship Packages Within D Days.
