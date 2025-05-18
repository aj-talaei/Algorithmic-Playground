// Problem: Construct Binary Tree from Inorder and Postorder Traversal
// Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
//
// Description:
// Given two integer arrays `inorder` and `postorder` where `inorder` is the inorder traversal
// of a binary tree and `postorder` is the postorder traversal of the same tree (with unique values),
// reconstruct and return the binary tree's root.
//
// Constraints:
// - 1 <= inorder.length == postorder.length <= 2000
// - Values in inorder and postorder are unique.

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    vector<int> post;
    unordered_map<int,int> indexMap;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        post = postorder;
        // Build a value->index map for inorder to allow O(1) lookups
        for (int i = 0; i < n; ++i) {
            indexMap[inorder[i]] = i;
        }
        return build(0, n - 1, 0, n - 1);
    }

private:
    // Builds tree from inorder[inL..inR] and postorder[postL..postR]
    TreeNode* build(int inL, int inR, int postL, int postR) {
        if (inL > inR || postL > postR) return nullptr;
        int rootVal = post[postR];
        TreeNode* root = new TreeNode(rootVal);
        int idx = indexMap[rootVal];
        int leftSize = idx - inL;
        root->left = build(inL, idx - 1, postL, postL + leftSize - 1);
        root->right = build(idx + 1, inR, postL + leftSize, postR - 1);
        return root;
    }
};
