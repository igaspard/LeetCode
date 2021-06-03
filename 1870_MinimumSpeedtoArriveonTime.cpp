class Solution {
   public:
    bool canReachInTime(const vector<int>& dist, const double hour, const int speed) {
        double takes = 0.0;
        for (int i = 0; i < N - 1; ++i) takes += ceil((double)dist[i] / speed);
        takes += (double)dist[N - 1] / speed;

        return takes <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        N = dist.size();
        if (hour < N - 1) return -1;

        int left = 1, right = 1e7, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (canReachInTime(dist, hour, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }

   private:
    int N;
};