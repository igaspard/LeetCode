class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto str : tokens) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                auto right = s.top(); s.pop();
                auto left = s.top(); s.pop();
                if (str == "+") s.push(left + right);
                else if (str == "-") s.push(left - right);
                else if (str == "*") s.push(left * right);
                else if (str == "/") s.push(left / right);
            } else {
                s.push(stoi(str));
            }
        }
        return s.top();
    }
};

// stack
// Runtime: 8 ms, faster than 87.80% of C++ online submissions for Evaluate Reverse Polish Notation.
// Memory Usage: 12 MB, less than 54.58% of C++ online submissions for Evaluate Reverse Polish Notation.
