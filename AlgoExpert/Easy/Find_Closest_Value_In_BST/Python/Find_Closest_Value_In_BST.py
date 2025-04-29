"""
Problem Name: Find Closest Value in BST
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Given a Binary Search Tree (BST) and a target integer value, find the closest value to that target in the BST.

Time Complexity: Average case O(log n), Worst case O(n)
Space Complexity: Average case O(log n), Worst case O(n)
"""

class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def findClosestValueInBst(tree, target):
    return findClosestHelper(tree, target, float('inf'))

def findClosestHelper(tree, target, closest):
    if tree is None:
        return closest

    if abs(target - closest) > abs(target - tree.value):
        closest = tree.value

    if target < tree.value:
        return findClosestHelper(tree.left, target, closest)
    elif target > tree.value:
        return findClosestHelper(tree.right, target, closest)
    else:
        return closest

