// Problem: Convert Sorted Array to Height Balanced BST
// Link: https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
//
// Description:
// Given an integer array `nums` sorted in ascending order, construct a height-balanced
// binary search tree (BST). A height-balanced BST is one in which the depths of the two
// subtrees of every node never differ by more than 1.
//
// Example:
//   Input:  nums = [-10,-3,0,5,9]
//   Output: A valid BST is [0,-3,9,-10,null,5], which corresponds to:
//
//          0
//         / \
//       -3   9
//       /   /
//    -10   5
//
// Constraints:
//   1 <= nums.size() <= 10^4
//
// Time Complexity: O(n)
// Space Complexity: O(log n) [recursion stack]

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        return build(nums, 0, int(nums.size()) - 1);
    }

private:
    TreeNode* build(const vector<int>& a, int lo, int hi) {
        if (lo > hi) return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode* node = new TreeNode(a[mid]);
        node->left  = build(a, lo,   mid - 1);
        node->right = build(a, mid + 1, hi);
        return node;
    }
};
