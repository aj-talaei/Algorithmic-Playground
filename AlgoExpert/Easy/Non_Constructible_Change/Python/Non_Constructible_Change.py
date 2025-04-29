"""
Problem Name: Non-Constructible Change
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Given an array of positive integers representing the values of coins in your possession,
write a function that returns the minimum amount of change (minimum sum of money) that you cannot create.

Time Complexity: O(n log n)
Space Complexity: O(1)
"""

def nonConstructibleChange(coins):
    coins.sort()
    currentExchangeCreated = 0
    for coin in coins:
        if coin > currentExchangeCreated + 1:
            return currentExchangeCreated + 1
        currentExchangeCreated += coin
    return currentExchangeCreated + 1

