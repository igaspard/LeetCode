class Solution {
   public:
    string simplifyPath(string path) {
        deque<string> s;

        int i = 0;
        while (i < path.length()) {
            string sub = "";

            while (path[i] == '/') ++i;

            if (path[i] == '\0') break; // check end of path after skip the '/'

            while (path[i] != '/' && path[i] != '\0') sub += path[i++];
            ++i; // after collecting the sub path jump to the next path[i]

            if (sub == "..") {
                if (!s.empty()) s.pop_back();
            } else if (sub != ".") {
                s.emplace_back(sub);
            }
        }

        string ans = "";
        while (!s.empty()) {
            ans.append("/");
            ans.append(s.front());
            s.pop_front();
        }

        return ans.empty() ? "/" : ans;
    }
};

// Stack, use deque for easy access to front and back
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Simplify Path.
// Memory Usage: 7.4 MB, less than 95.23% of C++ online submissions for Simplify Path.

class Solution {
   public:
    string simplifyPath(string path) {
        stack<string> s;

        int i = 0;
        while (i < path.length()) {
            string sub;
            while (path[i] == '/') ++i;

            if (path[i] == '\0') break;

            while (path[i] != '\0' && path[i] != '/') sub += path[i++];
            ++i;

            if (sub == "..") {
                if (!s.empty()) s.pop();
            } else if (sub != ".") {
                s.push(sub);
            }
        }

        string ans = "";
        while (!s.empty()) {
            ans = s.top() + ans;
            ans = '/' + ans;
            s.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};

// stack
// seperate each sub directory and push into stack,
// if we meet "..", pop stack, "." ingore it
// Runtime: 8 ms, faster than 57.07% of C++ online submissions for Simplify Path.
// Memory Usage: 10.9 MB, less than 14.32% of C++ online submissions for Simplify Path.