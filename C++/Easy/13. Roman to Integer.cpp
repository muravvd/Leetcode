/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Given a roman numeral, convert it to an integer.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int answer = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case 'M':
                    answer += 1000;
                    break;
                case 'D':
                    answer += 500;
                    break;
                case 'C':
                    if (s[i + 1] == 'M') {
                        answer += 900;
                        i++;
                        break;
                    }
                    if (s[i + 1] == 'D') {
                        answer += 400;
                        i++;
                        break;
                    }
                    answer += 100;
                    break;
                case 'L':
                    answer += 50;
                    break;
                case 'X':
                    if (s[i + 1] == 'L') {
                        answer += 40;
                        i++;
                        break;
                    }
                    if (s[i + 1] == 'C') {
                        answer += 90;
                        i++;
                        break;
                    }
                    answer += 10;
                    break;
                case 'V':
                    answer += 5;
                    break;
                case 'I':
                    if (s[i + 1] == 'V') {
                        answer += 4;
                        i++;
                        break;
                    }
                    if (s[i + 1] == 'X') {
                        answer += 9;
                        i++;
                        break;
                    }
                    answer += 1;
                    break;
            }
        }
        return answer;
    }
};


int main() {
    Solution test;
    string num;
    cin >> num;
    cout << test.romanToInt(num);
}
