// Source: https://leetcode.com/problems/diameter-of-binary-tree/
// Description: Given the root of a binary tree, return the length of the diameter of the tree. 
// The diameter is the number of edges on the longest path between any two nodes.

#include <algorithm>

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
    int bestDiameter = 0;
    
    // Returns the height of `node`, while updating bestDiameter.
    int height(TreeNode* node) {
        if (!node) return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        // The longest path through this node uses both subtrees.
        bestDiameter = std::max(bestDiameter, lh + rh);
        // Height is max depth of subtrees plus this node.
        return 1 + std::max(lh, rh);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        bestDiameter = 0;
        height(root);
        return bestDiameter;
    }
};
