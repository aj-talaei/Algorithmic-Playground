/*
Problem Name: Sorted Squared Array
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Write a function that takes in a non-empty array of integers that are sorted in ascending order
and returns a new array of the same length with the squares of the original integers also sorted in ascending order.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <cmath>
using namespace std;

vector<int> sortedSquaredArray(vector<int>& array) {
    int n = array.size();
    vector<int> sortedSquares(n, 0);
    int left = 0, right = n - 1;

    for (int i = n - 1; i >= 0; --i) {
        int leftValue = array[left];
        int rightValue = array[right];
        if (abs(leftValue) > abs(rightValue)) {
            sortedSquares[i] = leftValue * leftValue;
            left++;
        } else {
            sortedSquares[i] = rightValue * rightValue;
            right--;
        }
    }
    return sortedSquares;
}


