// Source : https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        vector<pair<int, int>> nodes; // {depth, value}
        int i = 0, n = S.size();

        // Parse the input string
        while (i < n) {
            int depth = 0;
            while (i < n && S[i] == '-') {
                depth++;
                i++;
            }
            int val = 0;
            while (i < n && isdigit(S[i])) {
                val = val * 10 + (S[i++] - '0');
            }
            nodes.push_back({depth, val});
        }

        stack<TreeNode*> st;

        for (auto& [d, val] : nodes) {
            TreeNode* node = new TreeNode(val);
            // Ensure stack has only ancestors at depth d - 1
            while (st.size() > d) st.pop();

            if (!st.empty()) {
                if (!st.top()->left) st.top()->left = node;
                else st.top()->right = node;
            }

            st.push(node);
        }

        // The root is the bottom of the stack
        while (st.size() > 1) st.pop();
        return st.top();
    }
};
