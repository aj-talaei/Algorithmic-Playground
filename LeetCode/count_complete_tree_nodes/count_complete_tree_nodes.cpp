// Problem: Count Complete Tree Nodes
// Given a complete binary tree, count the number of nodes.  
// A complete binary tree is one in which every level, except possibly the last, is completely filled,
// and all nodes in the last level are as far left as possible.

class Solution {
public:
    // Returns the height of a subtree following left or right edges
    int height(TreeNode* node, bool goLeft) {
        int h = 0;
        while (node) {
            h++;
            node = goLeft ? node->left : node->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh = height(root, true);
        int rh = height(root, false);
        if (lh == rh) {
            // Perfect tree: 2^h - 1 nodes
            return (1 << lh) - 1;
        }
        // Otherwise, recurse on subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
