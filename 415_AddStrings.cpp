class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int p1 = num1.length() - 1;
        int p2 = num2.length() - 1;
        
        string ans;
        while (p1 >= 0 || p2 >= 0) {
            int x1 = p1 >= 0 ? num1[p1] - '0' : 0;
            int x2 = p2 >= 0 ? num2[p2] - '0' : 0;
            int value = (x1 + x2 + carry) % 10;
            carry = (x1 + x2 + carry) / 10;
            ans.append(to_string(value));
            
            --p1;
            --p2;
        }
        
        if (carry) ans.append(to_string(carry));
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Runtime: 12 ms, faster than 38.47% of C++ online submissions for Add Strings.
// Memory Usage: 6.7 MB, less than 82.65% of C++ online submissions for Add Strings.