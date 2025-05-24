// Source: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Description: Given the root of a binary tree, flatten it in-place into a “linked list”
//              following the same order as a pre-order traversal. After flattening, each
//              node’s left pointer must be null and its right pointer points to the next
//              node in pre-order.

#include <cstddef>

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                // Find the rightmost node in left subtree
                TreeNode* pred = curr->left;
                while (pred->right) {
                    pred = pred->right;
                }
                // Rewire links
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

