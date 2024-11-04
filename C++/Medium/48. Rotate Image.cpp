/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.
*/


#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {    // 0ms  9mb
public:
    vector<vector<int>> rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j <= i; j++)
                swap(matrix[j][i], matrix[i][j]);   // transpose the matrix
        for (int i = 0; i < matrix.size(); i++)
            reverse(matrix[i].begin(), matrix[i].end());    // swap columns horizontally
        return matrix;
    }
};

void printV(const vector<vector<int>>& vec) {
    for (const auto& innerVec : vec) {
        cout << "[ ";
        for (int num : innerVec) {
            cout << num << " ";
        }
        cout << "] \n";
    }
    cout << endl;
}

int main() {
    Solution test;
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    printV(nums);
    printV(test.rotate(nums));
    return 0;
}