// Source: https://leetcode.com/problems/find-the-duplicate-number/
// Description: Given an array of n+1 integers where each integer is between 1 and n (inclusive), 
// there is exactly one duplicate number. Find that duplicate without modifying the array,
// using only O(1) extra space and runtime less than O(n^2).

#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(const vector<int>& nums) {
        int n = nums.size();
        // Use Floyd's Tortoise and Hare cycle detection on the "linked list"
        // where value -> next index.
        int slow = n, fast = n;
        do {
            slow = nums[slow - 1];
            fast = nums[nums[fast - 1] - 1];
        } while (slow != fast);
        
        // Find the entry point of the cycle.
        slow = n;
        while (slow != fast) {
            slow = nums[slow - 1];
            fast = nums[fast - 1];
        }
        return slow;
    }
};
