class Solution {
public:
    int calculate(string s) {
        list<char> ch_list;
        for (auto ch : s)
            ch_list.push_back(ch);

        return helper(ch_list);
    }
    int helper(list<char>& str) {
        stack<int> s;
        
        int num = 0;
        char sign = '+';
        while(!str.empty()) {
            char ch = str.front();
            str.pop_front();
            if (isdigit(ch)) num = num*10 + (ch - '0');
            
            if (ch == '(') num = helper(str);
            
            if ((!isdigit(ch) && ch != ' ') || str.empty()) {
                int pre;
                if (sign == '+') s.push(num);
                else if (sign == '-') s.push(-1*num);
                else if (sign == '*') {
                    pre = s.top();
                    s.pop();
                    s.push(pre*num);
                } else if (sign == '/') {
                    pre = s.top();
                    s.pop();
                    s.push(pre/num);
                }
                sign = ch;
                num = 0;
            }
            
            if (ch == ')') break;
        }
        
        int ans = 0;
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};

// Runtime: 72 ms, faster than 13.66% of C++ online submissions for Basic Calculator.
// Memory Usage: 26.3 MB, less than 18.68% of C++ online submissions for Basic Calculator.