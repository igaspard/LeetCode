class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDegree;
        for (auto word : words) {
            for (char ch : word) {
                inDegree[ch] = 0;
                graph[ch] = vector<char>();
            }
        }

        for (int i = 1; i < words.size(); ++i) {
            string pre = words[i - 1];
            string cur = words[i];
            if (cur.length() < pre.length() && pre.substr(0, cur.length()) == cur) return "";
            for (int j = 0; j < min(pre.length(), cur.length()); ++j) {
                if (pre[j] != cur[j]) {
                    graph[pre[j]].emplace_back(cur[j]);
                    ++inDegree[cur[j]];
                    break;
                }
            }
        }

        queue<char> q;
        for (auto entry : inDegree) {
            if (entry.second == 0) q.push(entry.first);
        }

        string ans;
        while (!q.empty()) {
            auto cur = q.front();
            ans.push_back(cur);
            q.pop();
            auto children = graph[cur];
            for (auto child : children) {
                --inDegree[child];
                if (inDegree[child] == 0) q.push(child);
            }
        }

        if (ans.length() != inDegree.size()) return "";
        return ans;
    }
};

// Topological Sort
// Time complexity: O(V+E)
// Space complexity: O(V+E)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Alien Dictionary.
// Memory Usage: 9.4 MB, less than 69.21% of C++ online submissions for Alien Dictionary.