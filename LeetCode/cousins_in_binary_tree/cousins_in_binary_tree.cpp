// Source: https://leetcode.com/problems/cousins-in-binary-tree/
// Description: Determine if two nodes in a binary tree are cousins (same depth but different parents).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    // Records depth and parent for target value
    bool dfs(TreeNode* node, int target, int depth, TreeNode* parent,
             int &outDepth, TreeNode* &outParent) {
        if (!node) return false;
        if (node->val == target) {
            outDepth = depth;
            outParent = parent;
            return true;
        }
        // Search left subtree
        if (dfs(node->left, target, depth + 1, node, outDepth, outParent))
            return true;
        // Search right subtree
        return dfs(node->right, target, depth + 1, node, outDepth, outParent);
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int dx = -1, dy = -1;
        TreeNode *px = nullptr, *py = nullptr;
        
        dfs(root, x, 0, nullptr, dx, px);
        dfs(root, y, 0, nullptr, dy, py);
        
        // Cousins if same depth but different parents
        return dx == dy && px != py;
    }
};
