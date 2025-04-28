/*
Problem Name: Three Number Sum
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Write a function that takes in a non-empty array of distinct integers and a target sum.
The function should find all triplets in the array that sum up to the target sum and return
a two-dimensional array of all these triplets. The numbers in each triplet should be ordered
in ascending order, and the triplets themselves should be ordered in ascending order with respect
to the numbers they hold.

If no three numbers sum up to the target sum, the function should return an empty array.

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    sort(array.begin(), array.end());
    vector<vector<int>> triplets;
    for (int i = 0; i < array.size() - 2; i++) {
        int left = i + 1;
        int right = array.size() - 1;
        while (left < right) {
            int currentSum = array[i] + array[left] + array[right];
            if (currentSum == targetSum) {
                triplets.push_back({array[i], array[left], array[right]});
                left++;
                right--;
            }
            else if (currentSum < targetSum) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    return triplets;
}
