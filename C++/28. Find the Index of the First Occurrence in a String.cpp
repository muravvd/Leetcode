/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                for (int j = 0, k = i; j < needle.size(); j++, k++) {
                    if (haystack[k] != needle[j]) {
                        break;
                    }
                    if (j == needle.size() - 1) {
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};


int main() {
    Solution test;
    string a = "sadbutsad";
    string b = "tsad";
    cout << test.strStr(a, b);
    return 0;
}
