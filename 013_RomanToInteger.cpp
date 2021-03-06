#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
       int sum = 0;
        for(int i=0; i < s.size(); i++) {
            switch (s[i]) {
                case 'M':
                    sum += 1000;
                    break;
                case 'C':
                    if (i+1<s.size()) {
                        if (s[i+1]=='M') {
                            sum += 900;
                            i++;
                        }
                        else if (s[i+1]=='D'){
                            sum += 400;
                            i++;
                        }
                        else
                            sum += 100;
                    }
                    else
                        sum += 100;
                    break;
                case 'D':
                    sum += 500;
                    break;
                case 'X':
                    if (i+1<s.size()) {
                        if (s[i+1]=='C') {
                            sum += 90;
                            i++;
                        } else if (s[i+1]=='L') {
                            sum += 40;
                            i++;
                        } else {
                            sum += 10;
                        }
                    } else {
                        sum += 10;
                    }
                    break;
                case 'L':
                    sum += 50;
                    break;
                case 'I':
                    if (i+1<s.size()) {
                        if (s[i+1]=='X') {
                            sum += 9;
                            i++;
                        } else if (s[i+1]=='V') {
                            sum += 4;
                            i++;
                        } else {
                            sum += 1;
                        }
                    } else {
                        sum += 1;
                    }
                    break;
                case 'V':
                    sum += 5;
                    break;
            }
        }
        return sum;
    }
};

int main(int argc, char const *argv[]) {
    Solution mysolution;
    cout<<"Ronam Numeral MMMCMXCIV: "<<mysolution.romanToInt("MMMCMXCIV");
    return 0;
}
