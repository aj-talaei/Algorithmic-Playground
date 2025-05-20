// Source: https://leetcode.com/problems/count-of-range-sum/
// Description:
//   Given an integer array nums, returns the count of range sums that lie in [lower, upper] inclusive.
//   A range sum S(i, j) = nums[i] + … + nums[j].  
//   Uses a divide‐and‐conquer (merge sort) approach to achieve O(n log n) time.

#include <vector>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        for (int i = 0; i < n; ++i)
            sums[i + 1] = sums[i] + nums[i];
        return (int)countWhileMerge(sums, 0, n + 1, lower, upper);
    }

private:
    long long countWhileMerge(vector<long long>& sums, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        int mid = left + (right - left) / 2;
        long long cnt = 0;
        cnt += countWhileMerge(sums, left, mid, lower, upper);
        cnt += countWhileMerge(sums, mid, right, lower, upper);

        int j1 = mid, j2 = mid;
        for (int i = left; i < mid; ++i) {
            while (j1 < right && sums[j1] - sums[i] < lower) ++j1;
            while (j2 < right && sums[j2] - sums[i] <= upper) ++j2;
            cnt += j2 - j1;
        }

        // merge the two sorted halves
        vector<long long> tmp;
        tmp.reserve(right - left);
        int i = left, j = mid;
        while (i < mid || j < right) {
            if (j == right || (i < mid && sums[i] < sums[j]))
                tmp.push_back(sums[i++]);
            else
                tmp.push_back(sums[j++]);
        }
        for (int k = 0; k < tmp.size(); ++k)
            sums[left + k] = tmp[k];

        return cnt;
    }
};
