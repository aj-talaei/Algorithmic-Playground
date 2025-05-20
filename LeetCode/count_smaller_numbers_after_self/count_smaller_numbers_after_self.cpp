// Source: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Description:
//   Given an integer array `nums`, return an array `counts` where `counts[i]` is the number of
//   smaller elements to the right of `nums[i]`. This implementation uses a modified merge-sort
//   to achieve O(n log n) time.

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0), idx(n);
        iota(idx.begin(), idx.end(), 0);
        mergeCount(nums, idx, counts, 0, n);
        return counts;
    }

private:
    void mergeCount(const vector<int>& nums,
                    vector<int>& idx,
                    vector<int>& counts,
                    int left,
                    int right) {
        if (right - left <= 1) return;
        int mid = left + (right - left) / 2;
        mergeCount(nums, idx, counts, left, mid);
        mergeCount(nums, idx, counts, mid, right);

        vector<int> merged;
        merged.reserve(right - left);
        int i = left, j = mid, rightSmaller = 0;

        while (i < mid && j < right) {
            if (nums[idx[j]] < nums[idx[i]]) {
                // idx[j] is a smaller element to the right of idx[i]
                ++rightSmaller;
                merged.push_back(idx[j++]);
            } else {
                counts[idx[i]] += rightSmaller;
                merged.push_back(idx[i++]);
            }
        }
        while (i < mid) {
            counts[idx[i]] += rightSmaller;
            merged.push_back(idx[i++]);
        }
        while (j < right) {
            merged.push_back(idx[j++]);
        }
        // Write back into idx
        for (int k = 0; k < merged.size(); ++k) {
            idx[left + k] = merged[k];
        }
    }
};
