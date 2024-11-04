/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/


#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {        // 0ms  9mb
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        res.push_back(nums);
        while (next_permutation(nums.begin(), nums.end())) {
            for (int num : nums) {
                cur.push_back(num);
            }
            res.push_back(cur);
            cur.clear();
        }
        return res;
    }
};

void printV(const vector<vector<int>>& vec) {
    for (const auto& innerVec : vec) {
        cout << "[ ";
        for (int num : innerVec) {
            cout << num << " ";
        }
        cout << "] ";
    }
}

int main() {
    Solution test;
    vector<int> nums = {1,1,2};
    printV(test.permuteUnique(nums));
    return 0;
}