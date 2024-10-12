/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n,
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
*/

#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {              // 5ms
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (m == 0)
            nums1 = nums2;
        else {
            vector<int> nums3;
            int im = 0, in = 0, j = 0;
            while (im < m && in < n) {
                if (nums1[im] == nums2[in]) {
                    nums3.push_back(nums1[im]);
                    nums3.push_back(nums2[in]);
                    im++;
                    in++;
                    continue;
                }
                if (nums1[im] < nums2[in]) {
                    nums3.push_back(nums1[im]);
                    im++;
                    continue;
                }
                if (nums1[im] > nums2[in]) {
                    nums3.push_back(nums2[in]);
                    in++;
                }
            }
            while (in < n) {
                nums3.push_back(nums2[in]);
                in++;
            }
            while (im < m) {
                nums3.push_back(nums1[im]);
                im++;
            }
            nums1=nums3;
        }
        for (int i = 0; i < m + n; i++) {
            cout << nums1[i] << " ";
        }
    }
};
*/

/*class Solution {              // heap-buffer-overflow on nums1[im] in leetcode. Why?...
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int im = 0;
        if (m == 0)
            nums1 = nums2;
        else {
            while (nums1.size() > m) {
                nums1.pop_back();
            }
            while (!nums2.empty()) {
                if (nums1[im]>nums2[0]) {
                    nums1.insert(nums1.begin() + im++, nums2[0]);
                    nums2.erase(nums2.begin());
                    continue;
                }
                if (nums1[im]==nums2[0]) {
                    nums1.insert(nums1.begin() + im++, nums2[0]);
                    nums2.erase(nums2.begin());
                    im++;
                    continue;
                }
                im++;
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            cout << nums1[i] << " ";
        }
    }
};*/

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int k = m-- + n-- - 1;
        while (m >= 0 && n >= 0) {
            if (nums1[m] > nums2[n]) {
                nums1[k--] = nums1[m--];
            } else {
                nums1[k--] = nums2[n--];
            }
        }
        while (n >= 0) {
            nums1[k--] = nums2[n--];
        }
    }
};

int main() {
    Solution test;
    vector<int> nums1 = {-1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0};
    vector<int> nums2 = {-1, -1, 0, 0, 1, 2};
    test.merge(nums1, 5, nums2, 6);
    for (int num : nums1) {
        std::cout << num << " ";
    }
    return 0;
}