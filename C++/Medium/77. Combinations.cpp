/*
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
*/

#include <iostream>
#include <vector>
using namespace std;

void printV(const vector<vector<int>> &vec) {
    cout << "| ";
    for (const auto &row: vec) {
        for (int val: row)
            cout << val << " ";
        cout << "| ";
    }
}

class Solution {
public:
    void backtrack(int i, int n, int k, vector<int> &cur, vector<vector<int>> &res) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        while (i <= n) {
            cur.push_back(i);
            backtrack(i + 1, n, k, cur, res);
            cur.pop_back();
            i++;
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(1, n, k, cur, res);
        return res;
    }
};

int main() {
    Solution test;
    printV(test.combine(4, 3));
    return 0;
}
