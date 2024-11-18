/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length).
For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.
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
    // brute, O(n)  0ms 17mb
public:
    bool search(vector<int> &nums, int target) {
        for (int num: nums)
            if (num == target)
                return true;
        return false;
    }
};

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        // best O(log n) | worst O(n)
        int k = findPivot(nums), m = 0, n = nums.size() - 1;
        if (nums[0] == target || nums[nums.size() - 1] == target)
            return true;
        while (nums[m] == nums[n] && m < n) {
            m++;
            n--;
        }
        if (nums[m] == target)
            return true;
        if (m >= n)
            return false;
        return find(nums, target, m, k - 1) || find(nums, target, k, n);
    }

    bool find(vector<int> &nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }

    int findPivot(vector<int> &nums) {
        // best O(log n) | worst O(n)
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            else {
                // duplicates
                while (right > left && nums[right] == nums[right - 1])
                    right--;
                right--;
            }
        }
        return left; // Pivot point
    }
};

int main() {
    Solution test;
    vector<int> nums = {2,2,2,3,2,2,2};
    printV(nums);
    cout << test.search(nums, 3) << endl;
    return 0;
}
