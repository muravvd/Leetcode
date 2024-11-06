/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

#include <algorithm>
#include <iostream>
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

class Solution2 {
    // O(n log(m))      0ms 12mb
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            if (i < n - 1 && matrix[i][0] <= target && matrix[i + 1][0] > target)
                if (binary_search(matrix[i].begin(), matrix[i].end(), target))
                    return true;
                else
                    return false;
        if (binary_search(matrix[n - 1].begin(), matrix[n - 1].end(), target))
            return true;
        return false;
    }
};

class Solution3 {
    // O(log(n) + log(m))         0ms 12mb
public:
    bool binarySearchRow(const vector<int> &row, int target) {
        int left = 0, right = row.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == target)
                return true;
            if (row[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n - 1;
        while (low <= high) {
            // binary search for needed row
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] <= target && matrix[mid][m - 1] >= target) // needed row
                return binarySearchRow(matrix[mid], target);
            if (matrix[mid][m - 1] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};

class Solution {
    // O(log m*n), flattened matrix. Creating array would be O(m * n + log(m * n)). 0ms 12mb
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = n * m - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / m][mid % m];    // convert for comparison
            if (midValue == target)
                return true;
            if (midValue < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

int main() {
    Solution test;
    vector<vector<int> > Grid = {{1}, {3}};
    vector<vector<int> > Grid2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    printGrid(Grid2);
    bool result = test.searchMatrix(Grid2, 11);
    cout << (result ? "Found" : "Not Found") << endl;
    return 0;
}
