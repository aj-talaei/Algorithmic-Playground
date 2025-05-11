// Problem: Binary Tree Level Order Traversal II
// Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Difficulty: Medium
// Author: Amir Javid Talaei
//
// Given the root of a binary tree, return the bottom-up level order traversal
// of its nodes' values. (i.e., from left to right, level by level from leaf to root).
//
// Example:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]
//
// Constraints:
// - The number of nodes in the tree is in the range [0, 2000].
// - -1000 <= Node.val <= 1000

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
