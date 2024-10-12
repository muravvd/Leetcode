/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.

Increment the large integer by one and return the resulting array of digits.
*/


#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool move = false;
        if (digits[digits.size() - 1] < 9) {
            digits[digits.size() - 1]++;
            return digits;
        }
        for (int i = digits.size() - 1; i > 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            if (i == 1)
                move = true;
            digits[i] = 0;
        }
        if (digits[0] == 9) {
            digits[0] = 0;
            digits.push_back(1);
            std::rotate(digits.rbegin(), digits.rbegin() + 1, digits.rend());
            move = false;
        }
        if (move)
            digits[0]++;
        return digits;
    }
};


int main() {
    Solution test;
    vector<int> x = {8, 9, 9, 9};
    x = test.plusOne(x);
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    }
    return 0;
}
