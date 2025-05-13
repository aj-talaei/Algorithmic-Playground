// Problem: Candy
// Source: https://leetcode.com/problems/candy/
//
// Description:
// There are N children standing in a line. Each child is assigned a rating value.
// You must distribute candies to these children with the following rules:
// 1. Each child must have at least one candy.
// 2. Children with a higher rating get more candies than their neighbors.
//
// The goal is to compute the minimum number of candies you must give.
//
// Example:
// Input: [1,0,2]
// Output: 5
// Explanation: You can distribute candies as [2,1,2]

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;

        int n = ratings.size();
        vector<int> candies(n, 1);

        // Pass 1: Left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Pass 2: Right to left
        int total = candies[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            total += candies[i];
        }

        return total;
    }
};
