/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

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

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> paths(n, vector<int>(m, 0));
        paths[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
            paths[i][0] = paths[i - 1][0] + grid[i][0];
        for (int i = 1; i < m; i++)
            paths[0][i] = paths[0][i-1] + grid[0][i];
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                paths[i][j] = min(paths[i - 1][j], paths[i][j - 1]) + grid[i][j];
        return paths[n - 1][m - 1];
    }
};


int main() {
    Solution test;
    vector<vector<int> > Grid = {{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int> > Grid2 = {{1,2,3},{4,5,6}};
    printGrid(Grid2);
    cout << test.minPathSum(Grid2) << endl;
    return 0;
}
