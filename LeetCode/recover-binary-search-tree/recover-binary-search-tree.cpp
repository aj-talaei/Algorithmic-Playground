// Source : https://leetcode.com/problems/recover-binary-search-tree/

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        TreeNode *curr = root, *pred = nullptr;

        while (curr) {
            if (!curr->left) {
                // Detect swapped nodes
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                // Find the inorder predecessor
                pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    // Detect swapped nodes
                    if (prev && prev->val > curr->val) {
                        if (!first) first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        if (first && second) swap(first->val, second->val);
    }
};
