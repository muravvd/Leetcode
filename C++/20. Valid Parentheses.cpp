/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

#include <chrono>
#include <iostream>
#include <stack>
#include <string>
using namespace std;


/*
() parentheses
[] square brackets
{} braces
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> lastbracket;
        for (char ch: s) {
            switch (ch) {
                case '(':
                    lastbracket.push(ch);
                    continue;
                case ')':
                    if (lastbracket.empty() || lastbracket.top() != '(')
                        return false;
                    lastbracket.pop();
                    continue;
                case '[':
                    lastbracket.push(ch);
                    continue;
                case ']':
                    if (lastbracket.empty() || lastbracket.top() != '[')
                        return false;
                    lastbracket.pop();
                    continue;
                case '{':
                    lastbracket.push(ch);
                    continue;
                case '}':
                    if (lastbracket.empty() || lastbracket.top() != '{')
                        return false;
                    lastbracket.pop();
                // default:          // not necessary
            }
        }
        return lastbracket.empty();
    }
};


int main() {
    string strs = "]";
    Solution test;
    bool result = test.isValid(strs);
    cout << "result is " << result << endl;
    return 0;
}
