/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so
that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

#include <iostream>
#include <vector>
using namespace std;

void printV(vector<int> &v) {
    for (int i: v)
        cout << i << " ";
}

class Solution {
    // 0ms 10mb
public:
    void sortColors(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] > nums[j])
                    swap(nums[i], nums[j]);
        printV(nums);
    }
};

class Solution2 {
    // 0ms 10mb
public:
    void sortColors(vector<int> &nums) {
        int zero = 0, one = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 0)
                zero++;
            else if (nums[i] == 1)
                one++;
        for (int i = 0; i < nums.size(); i++)
            if (zero > 0) {
                nums[i] = 0;
                zero--;
            } else
            if (one > 0) {
                nums[i] = 1;
                one--;
            } else
                nums[i] = 2;
        printV(nums);
    }
};

int main() {
    Solution2 test;
    vector<int> nums = {2, 2, 1, 2, 0, 1};
    test.sortColors(nums);
    return 0;
}
