
// Source: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Description: Given a rotated sorted array without duplicates, find the minimum element in O(log n) time.

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(const vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        // If the array is not rotated, the first element is the minimum.
        if (nums[lo] <= nums[hi]) return nums[lo];
        // Binary search for the inflection point.
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            // If mid element is greater than the last, min must be to the right.
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                // Otherwise, min is at mid or to the left.
                hi = mid;
            }
        }
        return nums[lo];
    }
};
