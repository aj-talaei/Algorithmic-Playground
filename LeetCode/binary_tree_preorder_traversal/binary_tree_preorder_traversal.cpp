// Problem: Binary Tree Preorder Traversal
// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Difficulty: Easy
// Author: Amir Javid Talaei
//
// Given the root of a binary tree, return the preorder traversal of its nodes' values.
//
// Example:
// Input: root = [1,null,2,3]
// Output: [1,2,3]
//
// Constraints:
// - The number of nodes in the tree is in the range [0, 100].
// - -100 <= Node.val <= 100

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        if (root) stk.push(root);
        
        while (!stk.empty()) {
            TreeNode* node = stk.top(); stk.pop();
            result.push_back(node->val);
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }

        return result;
    }
};
