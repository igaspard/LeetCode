class Solution {
public:
    int numberOfDays(int Y, int M) {    
        if(M == 2) {
            if (Y % 4) return 28;
            else if (Y % 100) return 29;
            else if (Y % 400) return 28;
            else return 29;    
        } else if (M == 4 || M == 6 | M == 9 | M == 11)
            return 30;
        else {
            return 31;              
        }
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Days in a Month.
// Memory Usage: 6 MB, less than 28.00% of C++ online submissions for Number of Days in a Month.