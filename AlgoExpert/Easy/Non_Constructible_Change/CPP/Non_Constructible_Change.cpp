/*
Problem Name: Non-Constructible Change
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Given an array of positive integers representing the values of coins in your possession,
write a function that returns the minimum amount of change (minimum sum of money) that you cannot create.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include <vector>
#include <algorithm>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
    sort(coins.begin(), coins.end());
    int currentChangeCreated = 0;

    for (int coin : coins) {
        if (coin > currentChangeCreated + 1) {
            return currentChangeCreated + 1;
        }
        currentChangeCreated += coin;
    }

    return currentChangeCreated + 1;
}

