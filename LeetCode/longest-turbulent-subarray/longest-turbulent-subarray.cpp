// Source : https://leetcode.com/problems/longest-turbulent-subarray/

class Solution {
public:
    int maxTurbulenceSize(const vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return n;

        int maxLen = 1, left = 0;

        for (int right = 1; right < n; ++right) {
            int cmp = compare(arr[right - 1], arr[right]);
            if (cmp == 0) {
                left = right;
            } else if (right == n - 1 || cmp * compare(arr[right], arr[right + 1]) != -1) {
                maxLen = max(maxLen, right - left + 1);
                left = right;
            }
        }

        return maxLen;
    }

private:
    int compare(int a, int b) {
        return (a > b) - (a < b); // returns 1 if a > b, -1 if a < b, 0 if equal
    }
};
