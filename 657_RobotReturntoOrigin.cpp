class Solution {
public:
    bool judgeCircle(string moves) {
        int y = 0, x = 0;
        
        for(int i = 0; i < moves.length(); ++i) {
            if (moves[i] == 'L') 
                --x;
            else if (moves[i] == 'R')
                ++x;
            else if (moves[i] == 'U')
                ++y;
            else
                --y;
        }
        
        return (!x && !y) ? true : false;
    }
};

// Runtime: 8 ms, faster than 99.92% of C++ online submissions for Robot Return to Origin.
// Memory Usage: 8.3 MB, less than 5.84% of C++ online submissions for Robot Return to Origin.