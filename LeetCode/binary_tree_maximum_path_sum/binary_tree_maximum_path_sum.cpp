// Problem: Binary Tree Maximum Path Sum
// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Difficulty: Hard
// Author: Amir Javid Talaei
//
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes
// in the sequence has an edge connecting them. A node can appear only once in the sequence.
// The path does not need to pass through the root.
//
// The path sum is the sum of the node values in the path.
// Return the maximum path sum of any non-empty path.
//
// Example:
// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
//
// Constraints:
// - The number of nodes in the tree is in the range [1, 3 * 10^4].
// - -1000 <= Node.val <= 1000

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

private:
    int maxGain(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        // Recursively get the max gain from left and right subtrees
        int left = max(maxGain(node->left, maxSum), 0);  // Ignore negatives
        int right = max(maxGain(node->right, maxSum), 0);

        // Max path through the current node
        int localMax = node->val + left + right;

        // Update global maximum if necessary
        maxSum = max(maxSum, localMax);

        // Return the max gain including the current node and one subtree
        return node->val + max(left, right);
    }
};
