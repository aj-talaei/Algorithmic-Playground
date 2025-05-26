// Problem: https://leetcode.com/problems/house-robber/
// You are a robber trying to maximize the total amount of money stolen from houses 
// along a street. Adjacent houses cannot be robbed on the same night due to security systems.
// Given an array of non-negative integers representing the money at each house, 
// return the maximum amount you can rob without alerting the police.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0, prev2 = 0;
        for (int num : nums) {
            int current = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};
