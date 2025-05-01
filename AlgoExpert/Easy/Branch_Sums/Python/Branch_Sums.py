"""
Problem Name: Branch Sums
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Return a list of sums of all values from root to each leaf node in a binary tree.

Time Complexity: O(n)
Space Complexity: O(n)
"""

class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def branchSums(root):
    sums = []
    calculateBranchSum(root, 0, sums)
    return sums

def calculateBranchSum(node, runningSum, sums):
    if node is None:
        return
    newRunningSum = node.value + runningSum
    if node.right is None and node.left is None:
        sums.append(newRunningSum)
        return
    calculateBranchSum(node.left, newRunningSum, sums)
    calculateBranchSum(node.right, newRunningSum, sums)

