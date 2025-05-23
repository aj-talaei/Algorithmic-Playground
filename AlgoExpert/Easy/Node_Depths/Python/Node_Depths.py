"""
Problem Name: Node Depths
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
The depth of a node is the distance between the node and the root.
Return the sum of all node depths in the binary tree.

Time Complexity: O(n)
Space Complexity: O(h)
"""

class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def nodeDepths(root, depth=0):
    if root is None:
        return 0
    return depth + nodeDepths(root.left, depth + 1) + nodeDepths(root.right, depth + 1)
