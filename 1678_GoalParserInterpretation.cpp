class Solution {
public:
    string interpret(string command) {
        string ans;
        const int N = command.length();
        int i = 0;
        while (i < N) {
            if (command[i] == 'G') {
                ans.append("G");
                ++i;
            }
            
            if (command[i] == '(') {
                if (i+1 < N && command[i+1] == ')') {
                    ans.append("o");
                    i += 2;
                } else if (i + 3 < N && command[i+1] == 'a' && command[i+2] == 'l' && command[i+3] == ')') {
                    ans.append("a");
                    ans.append("l");
                    i += 4;
                }
            }
        }
        
        return ans;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Goal Parser Interpretation.
// Memory Usage: 6 MB, less than 90.34% of C++ online submissions for Goal Parser Interpretation.
