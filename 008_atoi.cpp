#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long sum = 0, i = 0;
        int positive;

        while(str[i]==' ')
            i++;

        if (str[i]=='-') {
            positive = -1;
            i++;
        }
        else if (str[i]=='+') {
            positive = 1;
            i++;
        }
        else
            positive = 1;

        while (str[i] >= '0' && str[i] <= '9') {
            sum = sum*10 + str[i++]-'0';
            if (sum*positive > std::numeric_limits<int>::max())
                return std::numeric_limits<int>::max();
            if (sum*positive < std::numeric_limits<int>::min())
                return std::numeric_limits<int>::min();
        }

        return sum*positive;
    }
};

int main(int argc, char const *argv[]) {
    Solution mysolution;
    cout<<mysolution.myAtoi("123")<<endl;
    cout<<mysolution.myAtoi("-12abc")<<endl;
    cout<<mysolution.myAtoi("+-12")<<endl; // 
    cout<<mysolution.myAtoi("      010")<<endl; // skip space
    cout<<mysolution.myAtoi("2147483648")<<endl;
    cout<<mysolution.myAtoi("9223372036854775809")<<endl; // bigger than max long long

    return 0;
}
