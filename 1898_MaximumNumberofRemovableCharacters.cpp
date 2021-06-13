class Solution {
   public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = removable.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isSub(s, p, removable, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }

   private:
    bool isSub(string A, string B, vector<int> remove, int k) {
        const int N = A.length();
        vector<bool> removed(N, false);
        for (int i = 0; i < k; ++i) removed[remove[i]] = true;

        const int M = B.length();
        int j = 0;
        for (int i = 0; i < N && j < M; i++) {
            if (removed[i]) continue;
            if (A[i] == B[j]) ++j;
        }
        return j == M;
    }
};

// binary search
// Runtime: 244 ms, faster than 20.00% of C++ online submissions for Maximum Number of Removable Characters.
// Memory Usage: 142.1 MB, less than 20.00% of C++ online submissions for Maximum Number of Removable
// Characters.

class Solution {
   public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        if (isSubsequence(s, p) == false) return 0;

        int left = 0, right = removable.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            vector<int> remove = {removable.begin(), removable.begin() + mid};
            string tmp = removeStr(s, remove);
            if (isSubsequence(tmp, p)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }

   private:
    bool isSubsequence(string A, string B) {
        int j = 0;
        const int N = B.length();
        for (int i = 0; i < A.length() && j < N; i++) {
            if (A[i] == B[j]) ++j;
        }
        return j == N;
    }

    string removeStr(string s, vector<int>& removable) {
        string ans;

        for (int i = 0; i < s.length(); ++i) {
            auto it = find(removable.begin(), removable.end(), i);
            if (it == removable.end()) ans.push_back(s[i]);
        }

        return ans;
    }
};

// binary search
// TLE
