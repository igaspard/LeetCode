class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int>& A, const vector<int>& B) {
            if (A[0] == B[0])
                return A[1] > B[1];
            else
                return A[0] < B[0];
        });

        const int N = properties.size();
        int ans = 0;
        int mx = INT_MIN;
        for (int i = N - 1; i >= 0; --i) {
            if (properties[i][1] < mx) ++ans; 
            mx = max(mx, properties[i][1]);
        }
        return ans;
    }
};

// sort the attack in ascending order and defense as descending order
// then check from the back and record the max defense value, it the current defense is smaller than the max defense
// count as answer
// Time complexity is O(nlogn)
// Runtime: 596 ms, faster than 92.74% of C++ online submissions for The Number of Weak Characters in the Game.
// Memory Usage: 125.1 MB, less than 95.52% of C++ online submissions for The Number of Weak Characters in the Game