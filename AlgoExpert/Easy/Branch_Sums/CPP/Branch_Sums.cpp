/*
Problem Name: Branch Sums
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Write a function that takes in a Binary Tree and returns a list of its branch sums ordered
from the leftmost branch sum to the rightmost.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
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

void calculateBranchSums(BinaryTree* node, int runningSum, vector<int>& sums) {
    if (node == nullptr) return;

    int newRunningSum = runningSum + node->value;

    if (node->left == nullptr && node->right == nullptr) {
        sums.push_back(newRunningSum);
        return;
    }

    calculateBranchSums(node->left, newRunningSum, sums);
    calculateBranchSums(node->right, newRunningSum, sums);
}

vector<int> branchSums(BinaryTree* root) {
    vector<int> sums;
    calculateBranchSums(root, 0, sums);
    return sums;
}


