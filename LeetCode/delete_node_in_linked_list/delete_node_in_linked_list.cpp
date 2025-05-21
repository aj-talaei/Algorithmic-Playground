// Source: https://leetcode.com/problems/delete-node-in-a-linked-list/
// Description: Given only a pointer to a non-tail node in a singly linked list, delete that node in-place.

#include <cstddef>

class Solution {
public:
    // Since we're guaranteed the node to delete is not the tail,
    // we copy the next node's value into it and bypass the next node.
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
