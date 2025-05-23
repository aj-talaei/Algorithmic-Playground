// Source: https://leetcode.com/problems/find-peak-element/
// Description: Find any peak element in an array (element greater than its neighbors) in O(log n) time.
//              You may assume num[-1] = num[n] = -∞, and nums[i] != nums[i+1].

#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            // If mid is less than its right neighbor, the peak must be in [mid+1, hi]
            if (nums[mid] < nums[mid + 1]) {
                lo = mid + 1;
            } else {
                // Otherwise the peak is in [lo, mid]
                hi = mid;
            }
        }
        return lo;
    }
};
