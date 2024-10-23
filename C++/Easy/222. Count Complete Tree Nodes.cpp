/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree,
and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
*/

#include <iostream>

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


/*class Solution {    // O(n)
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};*/

void deallocateTree(TreeNode *node) {
    if (node == nullptr)
        return;
    deallocateTree(node->left);
    deallocateTree(node->right);
    delete node;
}

int countLeft(TreeNode *node) {
    // O(log n)
    if (node == nullptr)
        return 0;
    return 1 + countLeft(node->left);
}

class Solution {
    // O(log(n)^2)
public:
    int countNodes(TreeNode *root) {
        if (!root)
            return 0;
        if (countLeft(root->left) == countLeft(root->right)) // starting binary
            return (1 << countLeft(root->left)) + countNodes(root->right); // left side complete, counting to the right
        return (1 << countLeft(root->right)) + countNodes(root->left); // right side complete, counting to the left
        // nodes = 2^h = 1 << h
    }
};

int main() {
    Solution test;
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                                  new TreeNode(3, new TreeNode(6), nullptr));
    std::cout << test.countNodes(root) << std::endl;
    deallocateTree(root);
    root = new TreeNode(1);
    std::cout << test.countNodes(root) << std::endl;
    deallocateTree(root);
    root = nullptr;
    std::cout << test.countNodes(root) << std::endl;
    deallocateTree(root);
    return 0;
}
