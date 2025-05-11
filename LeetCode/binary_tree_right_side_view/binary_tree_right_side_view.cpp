// Problem: Binary Tree Right Side View
// Link: https://leetcode.com/problems/binary-tree-right-side-view/
// Difficulty: Medium
// Author: Amir Javid Talaei
// 
// Given the root of a binary tree, imagine yourself standing on the right side of it,
// return the values of the nodes you can see ordered from top to bottom.
//
// Example:
// Input: [1,2,3,null,5,null,4]
// Output: [1,3,4]
//
// Constraints:
// - The number of nodes in the tree is in the range [0, 100].
// - -100 <= Node.val <= 100

class Solution {
public:
    void dfs(TreeNode* node, int level, vector<int>& result) {
        if (!node) return;
        if (result.size() < level) result.push_back(node->val);
        dfs(node->right, level + 1, result);
        dfs(node->left, level + 1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 1, result);
        return result;
    }
};
