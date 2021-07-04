class Solution {
   public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        const int N = dist.size();
        vector<int> arrive_time(N);

        for (int i = 0; i < N; ++i) arrive_time[i] = (dist[i] - 1) / speed[i];
        sort(arrive_time.begin(), arrive_time.end());

        for (int i = 0; i < N; ++i)
            if (i > arrive_time[i]) return i;

        return N;
    }
};

// sort
// Runtime: 104 ms, faster than 100.00% of C++ online submissions for Eliminate Maximum Number of Monsters.
// Memory Usage: 82.9 MB, less than 50.00% of C++ online submissions for Eliminate Maximum Number of Monsters.