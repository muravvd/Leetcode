/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

2 abc
3 def
4 ghi
5 jkl
6 mno
7 pqrs
8 tuv
9 wxyz
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    // iterative
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        unordered_map<char, string> letters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> res = {""};
        for (char digit: digits) {
            vector<string> temp;
            for (const string &curr: res) {
                for (char letter: letters[digit]) {
                    temp.push_back(curr + letter);
                }
            }
            res.swap(temp);
        }
        return res;
    }
};

int main() {
    Solution test;
    string str = "2";
    vector<string> result = test.letterCombinations(str);
    for (string i: result)
        cout << i << endl;
    return 0;
}
