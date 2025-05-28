// LeetCode: https://leetcode.com/problems/kth-largest-element-in-an-array/

// Problem:
// Find the k-th largest element in an unsorted array.
// Use a min-heap to track the k largest elements.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
