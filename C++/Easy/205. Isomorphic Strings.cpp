/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character, but a character may map to itself.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {     // 0ms
        unordered_map<char, char> charMap;
        unordered_map<char, char> reverseMap;
        for (int i = 0; i < s.length(); i++) {
            if (charMap.find(s[i]) == charMap.end()) {
                charMap[s[i]] = t[i];
            } else {
                if (charMap[s[i]] != t[i])
                    return false;
            }
            if (reverseMap.find(t[i]) == reverseMap.end()) {
                reverseMap[t[i]] = s[i];
            } else {
                if (reverseMap[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution test;
    cout << test.isIsomorphic("egg", "add") << endl;
    cout << test.isIsomorphic("foo", "bar") << endl;
    cout << test.isIsomorphic("paper", "title") << endl;
    cout << test.isIsomorphic("badc", "baba") << endl;
    return 0;
}
