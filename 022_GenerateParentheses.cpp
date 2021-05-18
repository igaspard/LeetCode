class Solution {
   public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string track;
        backtrack(n, n, track);
        return ans;
    }

    void backtrack(int left, int right, string &track) {
        if (left < 0 || right < 0) return;

        if (left > right) return;

        if (left == 0 && right == 0) {
            ans.emplace_back(track);
            return;
        }

        track.push_back('(');
        backtrack(left - 1, right, track);
        track.pop_back();

        track.push_back(')');
        backtrack(left, right - 1, track);
        track.pop_back();
    }
};
// backtrack

class ParenthesesString {
   public:
    string str;
    int openCnt = 0;
    int closeCnt = 0;

    ParenthesesString(const string& s, int open, int close) {
        this->str = s;
        this->openCnt = open;
        this->closeCnt = close;
    }
};

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        queue<ParenthesesString> queue;
        queue.push({"", 0, 0});

        while (!queue.empty()) {
            auto it = queue.front();
            queue.pop();

            if (it.openCnt == n && it.closeCnt == n) {
                ans.emplace_back(it.str);
            } else {
                if (it.openCnt < n) queue.push({it.str + '(', it.openCnt + 1, it.closeCnt});

                if (it.openCnt > it.closeCnt) queue.push({it.str + ')', it.openCnt, it.closeCnt + 1});
            }
        }

        return ans;
    }
};

// BFS
// Runtime: 4 ms, faster than 86.42% of C++ online submissions for Generate Parentheses.
// Memory Usage: 8.3 MB, less than 5.14% of C++ online submissions for Generate Parentheses.

class Solution {
   public:
    void addParentheses(int n, int left, int right, string str, vector<string>& ans) {
        if (right > left)
            return;
        else if (left > n)
            return;
        else if (str.size() == n * 2)
            ans.emplace_back(str);

        addParentheses(n, left + 1, right, str + "(", ans);
        addParentheses(n, left, right + 1, str + ")", ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        addParentheses(n, 0, 0, "", ans);

        return ans;
    }
};

// Runtime: 8 ms, faster than 54.08% of C++ online submissions for Generate Parentheses.
// Memory Usage: 20.7 MB, less than 18.19% of C++ online submissions for Generate Parentheses.