class Solution {
   public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0, start = 0;
        int max_repeat_cnt = 0;
        unordered_map<char, int> hash;

        for (int end = 0; end < answerKey.length(); ++end) {
            char right = answerKey[end];
            hash[right]++;
            max_repeat_cnt = max(max_repeat_cnt, hash[right]);
            // length of sliding window - max freq char in window > k
            while (end - start + 1 - max_repeat_cnt > k) {
                char left = answerKey[start];
                hash[left]--;
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};

// sliding window & hash to record the max freq char in window
// Runtime: 56 ms, faster than 33.33% of C++ online submissions for Maximize the Confusion of an Exam.
// Memory Usage: 10.2 MB, less than 33.33% of C++ online submissions for Maximize the Confusion of an Exam.
