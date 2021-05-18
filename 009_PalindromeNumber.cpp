class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int i = 0, j = s.length() - 1;
        
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        
        return true;
    }
};

class BestSolution {
public:
    int isPalindrome(int x) {
        // negative is not Palindrome, and last digit is zero but x is not zero case
        if (x < 0 || (x%10 == 0 && x != 0))
            return false;

        int rev = 0;
        while(x > rev) { // revert only reach to the middle
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        // handle odd case, get rid of the middle digit
        return (x == rev || x == rev/10);
    }
};

class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while(x) {
            ans = ans*10 + x%10;
            if (ans > INT_MAX || ans < INT_MIN)
                return 0;
            x /= 10;
        }
        return (int)ans;
    }
    bool isPalindrome(int x) {
        if (x<0)
            return false;
        else {
            if (x == reverse(x))
                return true;
            else
                return false;
        }
    }
};
