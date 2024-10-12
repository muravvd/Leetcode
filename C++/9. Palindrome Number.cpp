/*
Given an integer x, return true if x is a palindrome, and false otherwise.

An integer is a palindrome when it reads the same forward and backward.

For example, 121 is a palindrome while 123 is not.
*/

#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string str = to_string(x);
        int length = str.length();
        if (length == 1) return true;
        for (int i = 0; length > i * 2; i++)
            if (str[i] != str[length - i - 1]) return false;
        return true;
    }
};


int main() {
    Solution test;
    int num;
    cin >> num;
    test.isPalindrome(num);
    if (test.isPalindrome(num))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
