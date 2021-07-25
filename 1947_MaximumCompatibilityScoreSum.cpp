class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        const int M = students.size();
        const int N = students[0].size();

        sort(mentors.begin(), mentors.end());

        int ans = 0;
        do {
            int sum = 0;
            for (int j = 0; j < M; ++j) {
                for (int i = 0; i < N; ++i) {
                    if (students[j][i] == mentors[j][i]) ++sum;
                }
            }
            ans = max(ans, sum);
        } while (next_permutation(mentors.begin(), mentors.end()));

        return ans;
    }
};

// sort + permutation
// Runtime: 424 ms, faster than 70.00% of C++ online submissions for Maximum Compatibility Score Sum.
// Memory Usage: 10 MB, less than 100.00% of C++ online submissions for Maximum Compatibility Score Sum.