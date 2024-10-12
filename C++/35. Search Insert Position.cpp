/*
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target) {
                high = mid - 1;
                continue;
            }
            if (nums[mid] < target)
                low = mid + 1;
        }
        return low;
    }
};


int main() {
    Solution test;
    vector<int> a = {1, 3, 5, 6};
    int b = 4;
    cout << test.searchInsert(a, b);
    return 0;
}
