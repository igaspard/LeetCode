class Solution {
public:
    int calculate(string str) {
        stack<int> s;
        
        int num = 0;
        char sign = '+';
        for (int i = 0; i < str.length(); ++i) {
            char ch = str[i];
            if (isdigit(ch)) num = num*10 + (ch - '0');
            
            if ((!isdigit(ch) && ch != ' ') || i == str.length()-1) {
                int pre;
                switch (sign) {
                    case '+':
                        s.push(num);
                        break;
                    case '-':
                        s.push(-1*num);
                        break;
                    case '*':
                        pre = s.top();
                        s.pop();
                        s.push(pre*num);
                        break;
                    case '/':
                        pre = s.top();
                        s.pop();
                        s.push(pre/num);
                        break;
                    default:
                        break;
                }
                sign = ch;
                num = 0;
            }
        }
        
        int ans = 0;
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};

// Runtime: 12 ms, faster than 55.92% of C++ online submissions for Basic Calculator II.
// Memory Usage: 8.6 MB, less than 49.88% of C++ online submissions for Basic Calculator II.