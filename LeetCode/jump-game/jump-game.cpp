// Problem: Jump Game
// URL: https://leetcode.com/problems/jump-game/
// Given an array of non-negative integers `nums`, where each element represents the maximum jump length at that position, determine if you can reach the last index.

#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        int n = nums.size();
        for (int i = 0; i <= reachable && i < n; ++i) {
            reachable = max(reachable, i + nums[i]);
            if (reachable >= n - 1) return true;
        }
        return false;
    }
};
