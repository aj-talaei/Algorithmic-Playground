// File: sorted_list_to_bst.cpp
//
// Problem: Convert Sorted List to Height Balanced BST
// Link: https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
//
// Description:
// Given the head of a singly linked list where elements are sorted in ascending order,
// convert it to a height-balanced binary search tree (BST). A height-balanced BST is one
// where the depths of the two subtrees of every node never differ by more than 1.
//
// Example:
//   Input:  head = [-10, -3, 0, 5, 9]
//   Output: A valid BST is [0, -3, 9, -10, null, 5], which corresponds to:
//
//          0
//         / \
//       -3   9
//       /   /
//    -10   5
//
// Constraints:
//   The number of nodes in the list is in the range [0, 2×10^4].
//   -10^5 <= Node.val <= 10^5
//
// Time Complexity: O(n)
// Space Complexity: O(log n) [recursion stack]

// #include <vector>

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x): val(x), next(nullptr) {}
// };

// struct TreeNode {
//     int val;
//     TreeNode *left, *right;
//     TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = listLength(head);
        current = head;
        return buildTree(0, n - 1);
    }

private:
    ListNode* current;

    // Compute the length of the linked list.
    int listLength(ListNode* node) {
        int len = 0;
        while (node) {
            ++len;
            node = node->next;
        }
        return len;
    }

    // Recursively build BST in in-order fashion.
    TreeNode* buildTree(int lo, int hi) {
        if (lo > hi) return nullptr;

        int mid = lo + (hi - lo) / 2;
        // Build left subtree
        TreeNode* left = buildTree(lo, mid - 1);

        // 'current' now points to the node for this root
        TreeNode* root = new TreeNode(current->val);
        root->left = left;
        current = current->next;

        // Build right subtree
        root->right = buildTree(mid + 1, hi);
        return root;
    }
};
