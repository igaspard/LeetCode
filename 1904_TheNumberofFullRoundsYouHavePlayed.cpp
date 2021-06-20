class Solution {
   public:
    int numberOfRounds(string startTime, string finishTime) {
        int start_hour = stoi(startTime.substr(0, 2));
        int start_min = stoi(startTime.substr(3, 2));
        int finish_hour = stoi(finishTime.substr(0, 2));
        int finish_min = stoi(finishTime.substr(3, 2));

        int start_remain = start_min % 15;
        if (start_remain != 0) start_min = start_min - start_remain + 15;
        int finish_remain = finish_min % 15;
        if (finish_remain != 0) finish_min = finish_min - finish_remain;

        int ans = 0;
        if (finish_min < start_min) {
            --finish_hour;
            finish_min += 60;
        }
        ans += ((finish_min - start_min) / 15);

        if (finish_hour < start_hour) {
            finish_hour += 24;
        }
        ans += ((finish_hour - start_hour) * 4);

        return ans;
    }
};

// Greedy
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for The Number of Full Rounds You Have Played.
// Memory Usage: 6 MB, less than 57.14% of C++ online submissions for The Number of Full Rounds You Have
// Played.