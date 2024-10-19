/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

class Solution {
public:
    int maxDepth(TreeNode* node) {
        if (node == NULL)
            return 0;
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        return max(leftDepth, rightDepth) + 1;
    }
};

void deleteTree(TreeNode* node) {
    if (node == nullptr)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    Solution test;
    const auto root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    const auto root2 = new TreeNode(1, nullptr, new TreeNode(2));
    cout << test.maxDepth(root) << endl;
    cout << test.maxDepth(root2) << endl;
    deleteTree(root);
    deleteTree(root2);
    return 0;
};
