/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and
removing all non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include <iostream>
#include <ostream>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        for (char &c: s)
            c = std::tolower(c);
        int len = s.length() - 1, i = 0;
        while (i < len) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[len])) {
                len--;
                continue;
            }
            if (s[i] != s[len])
                return false;
            i++;
            len--;
        }
        return true;
    }
};


int main() {
    Solution test;
    string s = "A man, a plan, a canal: Panama";
    cout << test.isPalindrome(s);
    return 0;
};
