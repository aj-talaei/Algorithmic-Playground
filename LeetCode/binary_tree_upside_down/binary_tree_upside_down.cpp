
/********************************************************************************** 
 * 
 * Problem: Binary Tree Upside Down (Leetcode 156 - Medium)
 * 
 * Given a binary tree where all the right nodes are either leaf nodes with 
 * a sibling (a left node that shares the same parent node) or NULL,
 * 
 * Flip it upside down and turn it into a tree where the original right nodes 
 * turned into left leaf nodes. Return the new root.
 * 
 * Example:
 * Input:
 *       1
 *      / \
 *     2   3
 *    / \
 *   4   5
 * 
 * Output:
 *       4
 *      / \
 *     5   2
 *        / \
 *       3   1
 * 
 * Constraints:
 * - The tree will always have at least one node.
 * - All right nodes must either be leaf nodes with a sibling or NULL.
 * 
 * Follow-up:
 * - Could you solve it both iteratively and recursively?
 * 
 **********************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* right = nullptr;

        while (root) {
            TreeNode* next = root->left;

            root->left = right;
            right = root->right;
            root->right = prev;

            prev = root;
            root = next;
        }

        return prev;
    }
};
