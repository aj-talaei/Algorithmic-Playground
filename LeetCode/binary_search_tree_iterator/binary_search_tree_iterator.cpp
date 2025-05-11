// Problem: Binary Search Tree Iterator
// Link: https://leetcode.com/problems/binary-search-tree-iterator/
// Difficulty: Medium
// Author: Amir Javid Talaei
//
// Implement an iterator over a binary search tree (BST).
// Your BSTIterator class will be initialized with the root node of a BST.
// Calling next() will return the next smallest number in the BST.
//
// Example:
// Input: ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
//        [[[7,3,15,null,null,9,20]], [], [], [], [], [], [], []]
// Output: [null, 3, 7, true, 9, true, 15, true]
//
// Constraints:
// - The number of nodes in the tree is in the range [1, 10^5].
// - 0 <= Node.val <= 10^6
// - next() and hasNext() should run in average O(1) time and use O(h) memory, where h is the height of the tree.

#include <stack>
using namespace std;

class BSTIterator {
private:
    stack<TreeNode*> st;

    // Helper to push leftmost path to stack
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = st.top(); st.pop();
        if (node->right) {
            pushLeft(node->right);
        }
        return node->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};
