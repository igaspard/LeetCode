class Solution {
   public:
    bool canReach(string s, int minJump, int maxJump) {
        const int N = s.length();
        queue<int> q;
        q.push(0);

        int mx = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();

            for (int j = max(i + minJump, mx + 1); j <= min(i + maxJump, N - 1); ++j) {
                if (s[j] == '0') {
                    if (j == N - 1) return true;
                    q.push(j);
                }
            }
            mx = i + maxJump;
        }

        return false;
    }
};

// BFS
// Runtime: 56 ms, faster than 12.50% of C++ online submissions for Jump Game VII.
// Memory Usage: 19.6 MB, less than 25.00% of C++ online submissions for Jump Game VII.
