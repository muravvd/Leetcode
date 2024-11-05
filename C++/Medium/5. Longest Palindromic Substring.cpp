/*
Given a string s, return the longest palindromic substring in s.
A string is palindromic if it reads the same forward and backward.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution2 {
    // Manacher’s Algorithm w/o mirror      18ms    11mb
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;
        string t = "#";
        for (char c: s)
            t += c + string("#"); // preprocess for handling even-length palindromes
        vector<int> L(t.size(), 0); // length of the palindrome centered at L[i]
        int maxLen = 0, centerId = 0;
        for (int i = 0; i < t.size(); i++) {
            while (i + 1 + L[i] < t.size() && i - 1 - L[i] >= 0 && t[i + 1 + L[i]] == t[i - 1 - L[i]])
                L[i]++;
            if (L[i] > maxLen) {
                maxLen = L[i];
                centerId = i;
            }
        }
        int start = (centerId - maxLen) / 2; // because of delimiters
        return s.substr(start, maxLen);
    }
};

class Solution {
    // Manacher’s Algorithm - O(n)      0-7ms 11mb
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;
        string t = "#";
        for (char c: s)
            t += c + string("#"); // preprocess for handling even-length palindromes
        int C = 0, R = 0; // center, right boundary
        vector<int> L(t.size(), 0); // length of the palindrome centered at L[i]
        int maxLen = 0, centerId = 0;
        for (int i = 0; i < t.size(); i++) {
            int mirror = 2 * C - i;
            if (i < R)
                L[i] = min(R - i, L[mirror]);
            while (i + 1 + L[i] < t.size() && i - 1 - L[i] >= 0 && t[i + 1 + L[i]] == t[i - 1 - L[i]])
                L[i]++;
            if (i + L[i] > R) {
                C = i;
                R = i + L[i];
            }
            if (L[i] > maxLen) {
                maxLen = L[i];
                centerId = i;
            }
        }
        int start = (centerId - maxLen) / 2; // because of delimiters
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution test;
    string s = "babad";
    cout << test.longestPalindrome(s) << endl;
    return 0;
}
