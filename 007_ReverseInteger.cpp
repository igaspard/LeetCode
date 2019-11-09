#include <iostream>
#include <queue>
using namespace std;

class BestSolution {
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
};

class Solution {
public:
    int reverse(int x) {
        queue<int> q;
        int tmp = x;
        while (tmp) {
            int digit = tmp % 10;
            q.push(digit);
            tmp /= 10;
        }
        long out = 0;
        while(!q.empty()) {
            out = out*10 + q.front();
            q.pop();
        }
        if (out > INT_MAX || out < INT_MIN)
            return 0;
        else
            return (int)out;
    }
};

int main(int argc, char const *argv[]) {
    BestSolution mysolution;
    cout<<"Reverse 123: "<<mysolution.reverse(123)<<endl;
    cout<<"Reverse -123: "<<mysolution.reverse(-123)<<endl;
    cout<<"Reverse 120: "<<mysolution.reverse(120)<<endl;
    cout<<"Reverse Max int: "<<mysolution.reverse(INT_MAX)<<endl;
    cout<<"Reverse Min int: "<<mysolution.reverse(INT_MIN)<<endl;
    return 0;
}
