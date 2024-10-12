/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*                          14ms    20mb
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int i;
        for (i = 0; i < nums.size()-1; i += 2)
            if (nums[i] != nums[i + 1])
                return nums[i];
        return nums[i];
    }
};
*/

class Solution {            // 3ms - 15ms
public:
    int singleNumber(vector<int> &nums) {
        int x = 0;
        for (int y : nums)
            x ^= y;
        return x;
    }
};

// read more about bitwise XOR assignment

int main() {
    Solution test;
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};
    cout << test.singleNumber(nums);
    return 0;
};
