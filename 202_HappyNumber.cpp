class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        
        do {
            slow = SquareSumofDigit(slow);
            fast = SquareSumofDigit(SquareSumofDigit(fast));
        } while (slow != fast);
        
        return slow == 1;
    }
    
    int SquareSumofDigit(int num) {
        int sum = 0, digit;
        
        while (num > 0) {
            digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        
        return sum;
    }
};


// Fast & slow algorithms
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.
// Memory Usage: 6.1 MB, less than 18.19% of C++ online submissions for Happy Number.