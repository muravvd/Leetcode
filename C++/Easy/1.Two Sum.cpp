/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (nums[i] + nums[j] == target)
                    return {i, j};
        return {};
    }
};


int main() {
    std::vector<int> v = {1, 9, 55, 4, 5};
    int target;
    cin >> target;
    int n = v.size();
    for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                    if (v[i] + v[j] == target)
                        cout << i << " " << j << endl;
    //return i, j;
    return {};
}
