// Source: https://leetcode.com/problems/first-bad-version/
// Description: Given versions 1…n and an API `isBadVersion(version)` that returns true if a version is bad,
//              find the first bad version while minimizing API calls.

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                // mid might be the first bad version
                high = mid;
            } else {
                // first bad version must be after mid
                low = mid + 1;
            }
        }
        return low;
    }
};
