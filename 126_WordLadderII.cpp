class Solution {
   public:
    vector<vector<string>> ans;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        ans.clear();
        if (words.count(endWord) == 0) return ans;

        // bfs build graph
        words.erase(beginWord);
        queue<string> q;
        q.push(beginWord);

        unordered_map<string, unordered_set<string>> graph;
        bool bFound = false;
        while (!q.empty()) {
            int size = q.size();
            vector<string> visited;
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                if (cur == endWord) bFound = true;
                auto neighbors = neighbor(cur);
                for (auto n : neighbors) {
                    if (words.count(n) != 0) {
                        graph[cur].insert(n);
                        q.push(n);
                        visited.emplace_back(n);
                    }
                }
            }
            for (auto v : visited) words.erase(v);
        }

        vector<string> track;
        track.emplace_back(beginWord);
        dfs(graph, endWord, track);
        return ans;
    }

    void dfs(unordered_map<string, unordered_set<string>>& graph, string end, vector<string> track) {
        auto cur = track.back();
        if (cur == end) {
            ans.emplace_back(track);
            return;
        }

        for (auto child : graph[cur]) {
            track.emplace_back(child);
            dfs(graph, end, track);
            track.pop_back();
        }
    }

    vector<string> neighbor(string str) {
        vector<string> ans;
        for (int i = 0; i < str.length(); ++i) {
            char tmp = str[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                str[i] = ch;
                ans.emplace_back(str);
            }
            str[i] = tmp;
        }

        return ans;
    }
};

// bfs + dfs backtrack
// bfs build graph, dfs find all the paths
// Runtime: 36 ms, faster than 23.98% of C++ online submissions for Word Ladder II.
// Memory Usage: 49.7 MB, less than 5.45% of C++ online submissions for Word Ladder II.

class Solution {
   public:
    vector<vector<string>> ans;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for (auto w : wordList) words.insert(w);
        if (words.count(endWord) == 0) return ans;

        vector<string> track;
        track.emplace_back(beginWord);
        backtrack(words, endWord, track);
        return ans;
    }

    void backtrack(unordered_set<string>& words, string end, vector<string> track) {
        if (track.back() == end) {
            if (!ans.empty() && ans[0].size() > track.size()) {
                ans.clear();
                ans.emplace_back(track);
                return;
            } else if (ans.empty() || (!ans.empty() && ans[0].size() == track.size())) {
                ans.emplace_back(track);
                return;
            }
        }

        auto neighbors = neighbor(track.back());
        for (auto n : neighbors) {
            if (words.count(n) != 0) {
                track.emplace_back(n);
                words.erase(n);

                backtrack(words, end, track);

                track.pop_back();
                words.insert(n);
            }
        }
    }

    vector<string> neighbor(string str) {
        vector<string> ans;
        for (int i = 0; i < str.length(); ++i) {
            char tmp = str[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                str[i] = ch;
                ans.emplace_back(str);
            }
            str[i] = tmp;
        }

        return ans;
    }
};

// backtrack
// TLE