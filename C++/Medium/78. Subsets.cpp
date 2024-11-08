/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

#include <iostream>
#include <vector>
using namespace std;

void printV(const vector<vector<int>> &vec) {
    cout << "| ";
    for (const auto &row: vec) {
        for (int val: row)
            cout << val << " ";
        cout << "| ";
    }
}

class Solution {    // 0ms 8mb
public:
    void backtrack(int i, vector<int> &nums, vector<int> &cur, vector<vector<int>> &res) {
        res.push_back(cur);
        while (i < nums.size()) {
            cur.push_back(nums[i]);
            backtrack(i + 1, nums, cur, res);
            cur.pop_back();
            i++;
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int> > res;
        vector<int> cur;
        backtrack(0, nums, cur, res);
        return res;
    }
};

int main() {
    Solution test;
    vector<int> nums = {1, 2, 3};
    printV(test.subsets(nums));
    return 0;
}
