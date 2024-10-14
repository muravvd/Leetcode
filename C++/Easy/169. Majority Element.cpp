/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*class Solution {                    // 23ms
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        unordered_map<int, int> app; // appearances
        for (int x: nums) {
            if (app.find(x) == app.end())
                app[x]=1;
             else {
                app[x]++;
                if (app[x] > n/2)
                    return x;
            }
        }
        return 0;
    }
};*/

/*class Solution {                // 17ms
public:
    int majorityElement(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};*/

class Solution {                // Moore's Voting Algorithm         8ms
public:
    int majorityElement(vector<int> &nums) {
        int major = nums[0], count = 0;
        for (int x : nums) {
            if (count == 0)
                major = x;
            if (x == major)
                count++;
            else
                count--;
        }
        return major;
    }
};

int main() {
    Solution test;
    vector<int> v = {2,2,2,1,1,1,3,2,2,2,2};
    cout << test.majorityElement(v);
    return 0;
};
