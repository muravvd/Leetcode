/*
Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {     // 15-23ms
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};

int main() {
    Solution test;
    vector<int> nums = {1,2,3,4,1};
    cout << test.containsDuplicate(nums);
    return 0;
}
