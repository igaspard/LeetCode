class Solution {
   public:
    int chalkReplacer(vector<int>& chalk, int k) {
        const int N = chalk.size();
        int64_t sum = 0;
        for (auto c : chalk) sum += c;
        int K = k % sum;
        int ans = 0;
        while (K > 0) {
            if (chalk[ans] <= K) {
                K -= chalk[ans];
                ans = (ans + 1) % N;
            } else {
                return ans;
            }
        }

        return ans;
    }
};
// Greedy
// Runtime: 116 ms, faster than 100.00% of C++ online submissions for Find the Student that Will Replace the
// Chalk. Memory Usage: 74.2 MB, less than 75.00% of C++ online submissions for Find the Student that Will
// Replace the Chalk.