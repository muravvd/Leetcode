/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            for(;;) {
                if (prefix.empty())
                    return "";
                if (strs[i].find(prefix) == 0)
                    break;
                prefix.pop_back();
            }
        }
        return prefix;
    }
};


int main() {
    vector<string> strs = {"aac","cab","abb"};
    Solution test;
    string result = test.longestCommonPrefix(strs);
    cout << "result is " << result << endl;
    return 0;
}
