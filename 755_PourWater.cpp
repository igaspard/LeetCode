class Solution {
   public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        while (volume > 0) {
            int pos = k;
            while (pos > 0 && heights[pos - 1] <= heights[pos]) --pos;

            while (pos < k && heights[pos + 1] == heights[pos]) ++pos;

            if (pos == k) {
                while (pos < heights.size() - 1 && heights[pos + 1] <= heights[pos]) ++pos;
                while (pos > k && heights[pos - 1] == heights[pos]) --pos;
            }
            ++heights[pos];

            --volume;
        }

        return heights;
    }
};

// Greedy
// Runtime: 4 ms, faster than 88.66% of C++ online submissions for Pour Water.
// Memory Usage: 7.3 MB, less than 49.48% of C++ online submissions for Pour Water.