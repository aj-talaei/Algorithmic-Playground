// Problem: Binary Tree Postorder Traversal
// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Difficulty: Easy
// Author: Amir Javid Talaei
//
// Given the root of a binary tree, return the postorder traversal of its nodes' values.
//
// Example:
// Input: root = [1,null,2,3]
// Output: [3,2,1]
//
// Constraints:
// - The number of nodes in the tree is in the range [0, 100].
// - -100 <= Node.val <= 100

class Solution {
public:
    // Method 1: Modified preorder (Root-Right-Left) + reverse
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top(); s.pop();
            result.push_back(node->val);
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
