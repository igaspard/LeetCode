#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int factorial(int n) {
        int f = 1;
        for(int i = 1; i<=n; i++)
            f *= i;

        return f;
    }
    string getPermutation(int n, int k) {
        char order[n];
        for(int j = 0, i = '1'; j<n; j++, i++)
           order[j] = i;

        string out;
        int tmp = k - 1;
        for(int i = 1; i < n; i++) {
            int index = tmp / factorial(n-i);
            out.push_back(order[index]);
            //adjust the order arrays
            for (size_t j = index; j < n-i; j++) {
                order[j] = order[j+1];
            }
            tmp %= factorial(n-i);
        }
        out.push_back(order[0]);
        return out;
    }
};

int main(int argc, char const *argv[]) {
    Solution mysolution;
    
    for (size_t j = 2; j <= 9; j++) {
        for (size_t i = 1; i <= mysolution.factorial(j) ; i++) {
            cout<<mysolution.getPermutation(j, i)<<endl;
        }
    }

    return 0;
}
