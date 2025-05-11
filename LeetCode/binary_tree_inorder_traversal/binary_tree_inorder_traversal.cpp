// Problem: Binary Tree Inorder Traversal
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Difficulty: Easy
// Author: Amir Javid Talaei
//
// Given the root of a binary tree, return the inorder traversal of its nodes' values.
//
// Example:
// Input: root = [1,null,2,3]
// Output: [1,3,2]
//
// Constraints:
// - The number of nodes in the tree is in the range [0, 100].
// - -100 <= Node.val <= 100

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;

        while (root || !st.empty()) {
            // Go to the leftmost node
            while (root) {
                st.push(root);
                root = root->left;
            }
            // Visit node
            root = st.top(); st.pop();
            result.push_back(root->val);
            // Traverse right subtree
            root = root->right;
        }

        return result;
    }
};
