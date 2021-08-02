class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long int pre = 0, n = 0, cur = 0;

        do {
            ++n;
            cur = pre;
            cur += 12 * n * n; 
            
            pre = cur;
        } while (pre < neededApples);
        
        return n * 4 * 2;
    }
};

// n * 4 + 2*n*4 + (n+1 ~ 2n-1) * 8
// 12n + (2n-1 + n + 1) * (n - 1) / 2 * 8
// 12n + 12n*n - 12n = 12 * n ^ 2
// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Minimum Garden Perimeter to Collect Enough Apples.
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Minimum Garden Perimeter to Collect Enough Apples.