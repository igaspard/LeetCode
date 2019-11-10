class Solution {
public:
    void addParentheses(int n, int left, int right, string str, vector<string>& ans) {
        if (right > left)
            return;
        else if (left > n)
            return;
        else if(str.size() == n*2)
            ans.emplace_back(str);

        addParentheses(n, left+1, right,   str+"(", ans);
        addParentheses(n, left  , right+1, str+")", ans);
    }

    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;  
        
        addParentheses(n, 0, 0, "", ans);  
 
        return ans;
    }
};

// Runtime: 8 ms, faster than 54.08% of C++ online submissions for Generate Parentheses.
// Memory Usage: 20.7 MB, less than 18.19% of C++ online submissions for Generate Parentheses.