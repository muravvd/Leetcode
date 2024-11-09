/*
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that
each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have
the result be placed in the first part of the array nums. More formally, if there are k elements
after removing the duplicates, then the first k elements of nums should hold the final result.
It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the
input array in-place with O(1) extra memory.
*/

#include <iostream>
#include <vector>
using namespace std;

void printV(const vector<int> &vec) {
    for (const auto &num: vec) {
        cout << num << " ";
    }
    cout << endl;
}

class Solution2 {
    // O(n) 9ms 13mb
public:
    int removeDuplicates(vector<int> &nums) {
        int cur = nums[0], count = 1, k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == cur) {
                if (count < 2) {
                    count++;
                    nums[k++] = nums[i];
                }
            } else {
                cur = nums[i];
                count = 1;
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};

class Solution {
    //  O(n)    4ms 13mb
public:
    int removeDuplicates(vector<int> &nums) {
        int cur = INT_MIN, k = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != cur)
                cur = nums[i];
            else if (i + 1 < n && nums[i + 1] == nums[i])
                while (i + 1 < n && nums[i + 1] == nums[i])
                    i++;
            nums[k++] = nums[i];
        }
        printV(nums);
        return k;
    }
};

int main() {
    Solution test;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    printV(nums);
    cout << test.removeDuplicates(nums) << endl;
    return 0;
}
