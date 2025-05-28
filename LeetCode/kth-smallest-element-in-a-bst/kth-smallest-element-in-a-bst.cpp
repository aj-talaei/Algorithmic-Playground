// LeetCode: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Problem:
// Given a binary search tree (BST), return the k-th smallest element in it.
// In-order traversal of a BST yields nodes in sorted order.

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        inOrder(root, k, result);
        return result;
    }

private:
    void inOrder(TreeNode* node, int& k, int& result) {
        if (!node || k == 0) return;

        inOrder(node->left, k, result);

        if (--k == 0) {
            result = node->val;
            return;
        }

        inOrder(node->right, k, result);
    }
};
