/*
Problem Name: Node Depths
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
The depth of a node is the distance between the node and the tree's root.
Return the sum of all node depths in a binary tree.

Time Complexity: O(n)
Space Complexity: O(h)
*/

#include <iostream>
using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive function to calculate node depths
int nodeDepths(BinaryTree* root, int depth = 0) {
    if (root == nullptr) return 0;
    return depth + nodeDepths(root->left, depth + 1) + nodeDepths(root->right, depth + 1);
}


