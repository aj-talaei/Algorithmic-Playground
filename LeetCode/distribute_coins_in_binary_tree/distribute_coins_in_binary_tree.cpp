// Source: https://leetcode.com/problems/distribute-coins-in-binary-tree/
// Description: Given a binary tree with N nodes and N coins total, compute the minimum number of moves required so that each node has exactly one coin. In one move you may transfer one coin between two adjacent nodes (parent↔child).

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
    
private:
    // Returns the net coins that must be moved from this subtree to its parent.
    // Positive means excess coins to send up; negative means deficit to pull down.
    int dfs(TreeNode* node, int& moves) {
        if (!node) return 0;
        int leftBalance  = dfs(node->left,  moves);
        int rightBalance = dfs(node->right, moves);
        moves += std::abs(leftBalance) + std::abs(rightBalance);
        // Current balance = coins_here + coins_from_children − 1 (keep one for this node)
        return node->val + leftBalance + rightBalance - 1;
    }
};
