/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
   public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> times;
        for (auto employee : schedule)
            for (auto sch : employee) times.emplace_back(sch);

        sort(times.begin(), times.end(),
             [](const Interval &A, const Interval &B) { return A.start < B.start; });

        vector<Interval> merged;
        for (auto time : times) {
            if (merged.empty() || time.start > merged.back().end) {
                merged.emplace_back(time);
            } else {
                merged.back().end = max(time.end, merged.back().end);
            }
        }

        vector<Interval> result;
        for (int i = 0; i < merged.size() - 1; ++i) {
            result.push_back({merged[i].end, merged[i + 1].start});
        }
        return result;
    }
};

// Runtime: 32 ms, faster than 100.00% of C++ online submissions for Employee Free Time.
// Memory Usage: 11.4 MB, less than 5.93% of C++ online submissions for Employee Free Time.