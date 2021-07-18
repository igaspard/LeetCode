class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.count(endWord) == 0) return 0;

        unordered_set<string> begin;
        unordered_set<string> end;
        begin.insert(beginWord);
        end.insert(endWord);

        int ans = 1;
        while (!begin.empty() && !end.empty()) {
            if (begin.size() > end.size()) swap(begin, end);

            unordered_set<string> temp;
            for (auto w : begin) {
                auto neighbors = neighbor(w);
                for (auto n : neighbors) {
                    if (end.count(n) != 0) return ans + 1;
                    if (words.count(n) != 0) {
                        temp.insert(n);
                        words.erase(n);
                    }
                }
            }
            begin = temp;
            ++ans;
        }

        return 0;
    }

    vector<string> neighbor(string str) {
        vector<string> ans;
        for (int i = 0; i < str.length(); ++i) {
            char temp = str[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                str[i] = ch;
                ans.emplace_back(str);
            }
            str[i] = temp;
        }

        return ans;
    }
};

// bi-directions bfs, two sets, swap once begin is bigger than end, until they are intersection.
// Time complexity:(M^2 * N), M is the length of beginWord, N is the length of list of words
// Space complexity: O(M * N)
// Runtime: 44 ms, faster than 96.05% of C++ online submissions for Word Ladder.
// Memory Usage: 43.2 MB, less than 8.22% of C++ online submissions for Word Ladder.

class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;

        unordered_set<string> words(wordList.begin(), wordList.end());

        words.erase(beginWord);
        q.push(beginWord);

        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            ++ans;
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                if (cur == endWord) return ans;
                vector<string> neighbors = neighbor(cur);
                for (auto n : neighbors) {
                    if (words.count(n) != 0) {
                        words.erase(n);
                        q.push(n);
                    }
                }
            }
        }

        return 0;
    }

    vector<string> neighbor(string str) {
        vector<string> ans;
        for (int i = 0; i < str.length(); ++i) {
            char temp = str[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                str[i] = c;
                ans.emplace_back(str);
            }
            str[i] = temp;
        }
        return ans;
    }
};

// bfs
// Time complexity:(M^2 * N), M is the length of beginWord, N is the length of list of words
// Space complexity: O(M * N)
// Runtime: 212 ms, faster than 53.04% of C++ online submissions for Word Ladder.
// Memory Usage: 270.1 MB, less than 5.01% of C++ online submissions for Word Ladder.
