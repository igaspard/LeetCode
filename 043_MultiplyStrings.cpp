class Solution {
   public:
    const int K = 10;
    string multiply(string num1, string num2) {
        if (num1.length() < num2.length()) swap(num1, num2);
        if (num2 == "0") return "0";
        const int M = num2.length();
        const int N = num1.length();
        string ans;
        for (int i = M - 1; i >= 0; --i) {
            string cur;
            int carry = 0;
            for (int j = N - 1; j >= 0; --j) {
                int tmp = (num1[j] - '0') * (num2[i] - '0') + carry;
                int product = tmp % K;
                carry = tmp / K;
                cur = to_string(product) + cur;
            }
            if (carry != 0) cur = to_string(carry) + cur;
            int zero = M - i - 1;
            while (zero-- > 0) cur.append("0");
            ans = addStrings(ans, cur);
        }

        return ans;
    }

   private:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int idx1 = num1.length() - 1, idx2 = num2.length() - 1;
        string ans;
        while (idx1 >= 0 || idx2 >= 0) {
            int d1 = idx1 >= 0 ? num1[idx1] - '0' : 0;
            int d2 = idx2 >= 0 ? num2[idx2] - '0' : 0;
            int tmp = d1 + d2 + carry;
            int sum = tmp % K;
            carry = tmp / K;
            ans = to_string(sum) + ans;
            --idx1;
            --idx2;
        }

        if (carry != 0) ans = to_string(carry) + ans;
        return ans;
    }
};

// Runtime: 208 ms, faster than 6.47% of C++ online submissions for Multiply Strings.
// Memory Usage: 60.9 MB, less than 7.02% of C++ online submissions for Multiply Strings.