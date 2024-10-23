/*
Given an integer array nums and an integer k,
return true if there are two distinct indices i and j in the array
such that nums[i] == nums[j] and abs(i - j) <= k.
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*class Solution {    // 1796ms 63mb
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j <= i + k && j < nums.size(); j++) {
                if (nums[i] == nums[j] && abs(i - j) <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};*/

/*class Solution {    // 200ms 112mb
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        map<int, vector<int> > lastSeen;
        for (int i = 0; i < nums.size(); i++)
            lastSeen[nums[i]].push_back(i);
        for (const auto &pair: lastSeen) {
            const vector<int> &indices = pair.second;
            for (int i = 0; i < indices.size() - 1; ++i)
                if (indices[i + 1] - indices[i] <= k)
                    return true;
        }
        return false;
    }
};*/

class Solution {    //  51ms 81mb
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> lastSeen;
        for (int i = 0; i < nums.size(); i++) {
            if (lastSeen.contains(nums[i]))
                if (i - lastSeen[nums[i]] <= k)
                    return true;
            lastSeen[nums[i]] = i;  // basically a sliding window
        }
        return false;
    }
};

int main() {
    Solution test;
    vector<int> nums = {1, 2, 3, 1};
    cout << test.containsNearbyDuplicate(nums, 3) << endl; // 1
    nums = {1, 0, 1, 1};
    cout << test.containsNearbyDuplicate(nums, 1) << endl; // 1
    nums = {1, 2, 3, 1, 2, 3};
    cout << test.containsNearbyDuplicate(nums, 2) << endl; // 0
    return 0;
}
