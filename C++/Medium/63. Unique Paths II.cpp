/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid.
A path that the robot takes cannot include any square that is an obstacle.

You are given an m x n integer array grid.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
*/

#include <iostream>
#include <vector>
using namespace std;

void printObstacleGrid(const std::vector<std::vector<int> > &grid) {
    for (const auto &row: grid) {
        for (int cell: row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

class Solution {    // paths, 0ms 10mb
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        obstacleGrid[0][0] = 1;
        for (int i = 1; i < m; i++)
            if (obstacleGrid[i][0] == 1)
                obstacleGrid[i][0] = 0;
            else
                obstacleGrid[i][0] = obstacleGrid[i - 1][0];
        for (int j = 1; j < n; j++)
            if (obstacleGrid[0][j] == 1)
                obstacleGrid[0][j] = 0;
            else
                obstacleGrid[0][j] = obstacleGrid[0][j - 1];
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                else
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
        return obstacleGrid[m - 1][n - 1];
    }
};


int main() {
    Solution test;
    vector<vector<int> > obstacleGrid2 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int> > obstacleGrid = {{0, 1}, {0, 0}};
    vector<vector<int> > obstacleGrid3 = {
        {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0},
        {0, 0}, {0, 0}, {0, 0}, {0, 1}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 1}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
        {0, 0}, {0, 0}, {0, 0}, {0, 1}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}
    };
    printObstacleGrid(obstacleGrid2);
    cout << endl;
    cout << test.uniquePathsWithObstacles(obstacleGrid2) << endl;
    return 0;
}
