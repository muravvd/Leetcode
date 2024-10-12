/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.
*/


#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.length(), i=0;
        while(s[len-1] == ' ')
            len--;
        while (len>0) {
            if (s[len-1] == ' ')
                return i;
            len--;
            i++;
        }
        return i;
    }
};


int main() {
    Solution test;
    string s = "   fly me   to   the moon  ";
    cout << test.lengthOfLastWord(s);
    return 0;
}
