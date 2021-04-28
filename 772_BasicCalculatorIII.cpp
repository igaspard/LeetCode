class Solution {
public:
    int calculate(string s) {
        forward_list<char> ch_list;
        for (int i = (int)s.length()-1; i >= 0; --i)
            ch_list.emplace_front(s[i]);

        return helper(ch_list);
    }
    
    static int helper(forward_list<char>& str) {
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

// Runtime: 8 ms, faster than 27.59% of C++ online submissions for Basic Calculator III.
// Memory Usage: 13 MB, less than 15.61% of C++ online submissions for Basic Calculator III.
