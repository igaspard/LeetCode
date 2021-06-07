class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, h, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }

    bool canFinish(const vector<int>& piles, const int H, int speed) {
        int times = 0;
        for (auto p : piles) {
            int time = p / speed + ((p % speed > 0) ? 1 : 0);
            times += time;
        }

        return times <= H;
    }
};

// binary search the left bound to find the minimum speed
// Runtime: 32 ms, faster than 97.55% of C++ online submissions for Koko Eating Bananas.
// Memory Usage: 18.9 MB, less than 38.34% of C++ online submissions for Koko Eating Bananas.
