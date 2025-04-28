/*
Problem Name: Validate Subsequence
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Given two non-empty arrays of integers, determine whether the second array is a subsequence of the first one.

A subsequence of an array is a set of numbers that are in the same order as they appear in the array,
but not necessarily contiguous.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    int arrayIdx = 0;
    int seqIdx = 0;

    while (arrayIdx < array.size() && seqIdx < sequence.size()) {
        if (array[arrayIdx] == sequence[seqIdx]) {
            seqIdx++;
        }
        arrayIdx++;
    }

    return seqIdx == sequence.size();
}