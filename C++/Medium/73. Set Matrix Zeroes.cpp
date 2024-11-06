/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

void printGrid(const std::vector<std::vector<int> > &grid) {
    for (const auto &row: grid) {
        for (int cell: row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    cout << endl;
}

class Solution {
    // brute, repeating changes, 0ms 17mb
public:
    vector<vector<int> > setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<pair<int, int> > zeroPositions;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 0)
                    zeroPositions.push_back({i, j});
        for (auto pos: zeroPositions) {
            int row = pos.first;
            int column = pos.second;
            for (int k = 0; k < m; k++)
                matrix[row][k] = 0;
            for (int k = 0; k < n; k++)
                matrix[k][column] = 0;
        }
        return matrix;
    }
};

class Solution2 {
    // no repeating changes with sets, 4ms 18mb
public:
    vector<vector<int> > setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        set<int> zeroRows, zeroCols; // for uniques
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
        for (int i: zeroRows)
            for (int j = 0; j < m; j++)
                matrix[i][j] = 0;
        for (int j: zeroCols)
            for (int i = 0; i < n; i++)
                matrix[i][j] = 0;
        return matrix;
    }
};

class Solution3 {
    // no repeating changes with vectors, 5ms 17mb
public:
    vector<vector<int> > setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<bool> zeroRows(n, false);
        vector<bool> zeroColumns(m, false);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroColumns[j] = true;
                }
        for (int i = 0; i < n; i++)
            if (zeroRows[i])
                for (int j = 0; j < m; j++)
                    matrix[i][j] = 0;
        for (int i = 0; i < m; i++)
            if (zeroColumns[i])
                for (int j = 0; j < n; j++)
                    matrix[j][i] = 0;
        return matrix;
    }
};

int main() {
    Solution test;
    vector<vector<int> > Grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int> > Grid2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    printGrid(Grid2);
    printGrid(test.setZeroes(Grid2));
    return 0;
}
