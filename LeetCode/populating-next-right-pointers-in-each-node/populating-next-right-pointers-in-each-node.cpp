// source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left || !root->right) return root;

        // Connect left -> right
        root->left->next = root->right;

        // Connect right -> next subtree's left
        if (root->next) {
            root->right->next = root->next->left;
        }

        // Recur on left and right subtrees
        connect(root->left);
        connect(root->right);

        return root;
    }
};
