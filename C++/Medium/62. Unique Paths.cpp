/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot
can take to reach the bottom-right corner.
*/

#include <iostream>
#include <vector>
using namespace std;

int factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

class Solution2 {
    // Combinatorics, signed integer overflow
public:
    int uniquePaths(int m, int n) {
        // (m+n-2)! / (m-1)! * (n-1)!
        return factorial(m + n - 2) / (factorial(m - 1) * (factorial(n - 1)));
    }
};

class Solution3 {
    // Combinatorics, direct computation    0ms 7mb
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2; // total number of moves
        int k = min(m - 1, n - 1);
        long long res = 1;
        for (int i = 1; i <= k; ++i)
            res = res * (N - k + i) / i; // (N−k+1)*(N−k+2)*...*N / 1*2*...*K
        return res;
    }
};

/*
 * 1  1  1  1  1  1  1
 * 1  2  3  4  5  6  7
 * 1  3  6  10 15 21 28
*/

class Solution {
    // Paths    0ms 8mb
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > paths(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            paths[i][0] = 1;
        for (int j = 0; j < n; j++)
            paths[0][j] = 1;
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
        return paths[m-1][n-1];
    }
};


int main() {
    Solution test;
    cout << test.uniquePaths(3, 7) << endl;
    return 0;
}