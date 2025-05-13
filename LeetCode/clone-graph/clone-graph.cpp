/*
 * Leetcode Problem: Clone Graph
 *
 * Given a reference of a node in a connected undirected graph,
 * return a deep copy (clone) of the graph.
 *
 * Each node in the graph contains a value (int) and a list of its neighbors.
 *
 * Example:
 * Input: A graph like:
 *        1
 *       / \
 *      /   \
 *     0 --- 2
 *          / \
 *          \_/
 * Output: A deep copy of the graph.
 *
 * Constraints:
 * - The number of nodes in the graph is in the range [0, 100].
 * - 1 <= Node.val <= 100
 * - Node.val is unique for each node.
 * - There are no repeated edges and no self-loops in the graph.
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        q.push(node);

        visited[node] = new Node(node->val);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (auto neighbor : current->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[current]->neighbors.push_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};
