// Problem: Binary Tree Paths
// Link: https://leetcode.com/problems/binary-tree-paths/
// Difficulty: Easy
// Author: Amir Javid Talaei
//
// Given the root of a binary tree, return all root-to-leaf paths in any order.
//
// A leaf is a node with no children.
//
// Example:
// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]
//
// Constraints:
// - The number of nodes in the tree is in the range [1, 100].
// - -100 <= Node.val <= 100

#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;
        
        if (!path.empty()) path += "->";
        path += to_string(node->val);
        
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }
        
        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};
