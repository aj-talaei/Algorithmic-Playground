
// Problem: Construct Binary Tree from Preorder and Inorder Traversal
// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//
// Description:
// Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal
// of a binary tree and `inorder` is the inorder traversal of the same tree (with unique values),
// reconstruct and return the binary tree's root.
//
// Constraints:
// - 1 <= preorder.length == inorder.length <= 2000
// - Values in preorder and inorder are unique.

#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    vector<int> preorderVec;
    unordered_map<int,int> inorderIndex;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        preorderVec = preorder;
        // Build value->index map for inorder traversal
        for (int i = 0; i < n; ++i) {
            inorderIndex[inorder[i]] = i;
        }
        int preIndex = 0;
        return buildSubtree(0, n - 1, preIndex);
    }

private:
    // Recursively constructs the subtree spanning inorder indices [inL..inR].
    // preIndex tracks the current root in preorderVec.
    TreeNode* buildSubtree(int inL, int inR, int& preIndex) {
        if (inL > inR) return nullptr;
        int rootVal = preorderVec[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inorderIndex[rootVal];
        // Build left and right subtrees
        root->left  = buildSubtree(inL, mid - 1, preIndex);
        root->right = buildSubtree(mid + 1, inR, preIndex);
        return root;
    }
};
