/*
Given an integer rowIndex, return the rowIndex-th (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex + 1);
        row[0] = 1;
        for (long long k = 1; k <= rowIndex; ++k)
            row[k] = row[k - 1] * (rowIndex - k + 1) / k;
        return row;
    }
};

int main() {
    Solution test;
    vector<int> Row = test.getRow(30);
    for (int val: Row)
        cout << val << " ";
    return 0;
}
