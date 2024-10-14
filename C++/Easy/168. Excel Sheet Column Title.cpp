/*
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
*/

#include <algorithm>
#include <iostream>
#include <ranges>
using namespace std;

char getLetter(int num) {
    char letter = 'A';
    letter += (num - 1);
    return letter;
}

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "", alphabet = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        /*if (columnNumber < 27) {
            result += getLetter(columnNumber);      // 2ms slower
            return result;
        }*/
        while (columnNumber > 0) {
            if (columnNumber % 26 == 0) {
                result += 'Z';
                columnNumber -= 1;
            } else
                result += alphabet[columnNumber % 26];
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution test;
    int columnNumber = 701;
    cout << test.convertToTitle(columnNumber);
    return 0;
};
