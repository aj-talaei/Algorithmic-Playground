/*
Problem Name: Two Number Sum
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Write a function that takes in a non-empty array of distinct integers and a target sum. If any two numbers
in the input array sum up to the target sum, the function should return them in an array, in any order.
If no two numbers sum up to the target sum, the function should return an empty array.

You cannot add a number to itself to reach the target sum.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> twoNumberSum(vector<int>& array, int targetSum) {
        unordered_set<int> nums;
        for (int num : array) {
            int complement = targetSum - num;
            if (nums.find(complement) != nums.end()) {
                return {complement, num};
            }
            nums.insert(num);
        }
        return {};  // No two numbers found that sum to target
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> array = {3, 5, -4, 8, 11, 1, -1, 6};
    int targetSum = 10;
    vector<int> result = solution.twoNumberSum(array, targetSum);

    if (!result.empty()) {
        cout << "Two numbers that sum to target: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two numbers found." << endl;
    }

    return 0;
}
