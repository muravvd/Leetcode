/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.

The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int j = 1;
        if (nums.empty()) return 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};


int main() {
    Solution test;
    vector<int> nums = {1, 1, 2};
    cout << test.removeDuplicates(nums);
    return 0;
}
