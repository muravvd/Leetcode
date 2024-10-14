/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it
*/

#include <iostream>
#include <vector>
using namespace std;

std::vector<int> generateRow(int n) {
    std::vector<int> row(n + 1);
    row[0] = 1;
    for (int k = 1; k <= n; ++k)
        row[k] = row[k - 1] * (n - k + 1) / k;
    return row;
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};
        vector<vector<int>> Rows;
        for (int i = 0; i < numRows; i++)
            Rows.push_back(generateRow(i));
        return Rows;
    }
};

int main() {
    Solution test;
    vector<vector<int>> Rows = test.generate(5);
    for (auto row : Rows) {
       for (auto val : row)
           cout << val << " ";
        cout << endl;
    }
    return 0;
}
