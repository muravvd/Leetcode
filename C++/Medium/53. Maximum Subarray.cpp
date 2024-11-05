/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {    // Kadane’s Algorithm    O(n) T | O(1) S
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];
        int res = nums[0], maxEnding = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxEnding = max(maxEnding + nums[i], nums[i]);
            res = max(res, maxEnding);
        }
        return res;
    }
};

int main() {
    Solution test;
    vector<int> strs = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << test.maxSubArray(strs) << endl;
    return 0;
}
