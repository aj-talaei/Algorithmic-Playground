
/*
Problem Name: Find Closest Value in BST
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Given a Binary Search Tree (BST) and a target integer value, find the closest value to that target in the BST.

Time Complexity: Average case O(log n), Worst case O(n)
Space Complexity: Average case O(log n), Worst case O(n)
*/

class BST {
public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
    BST& insert(int val);
};
int findClosestValueInBstHelper(BST* tree, int target, int closest) {
    if (tree == nullptr) {
        return closest;
    }
    if (abs(target - closest) > abs(target - tree->value)) {
        closest = tree->value;
    }
    if (target > tree->value) {
        return findClosestValueInBstHelper(tree->right, target, closest);
    } else if (target < tree->value) {
        return findClosestValueInBstHelper(tree->left, target, closest);
    } else {
        return closest;
    }
}

int findClosestValueInBst(BST* tree, int target) {
    // Write your code here.
    return findClosestValueInBstHelper(tree, target, tree->value);
}