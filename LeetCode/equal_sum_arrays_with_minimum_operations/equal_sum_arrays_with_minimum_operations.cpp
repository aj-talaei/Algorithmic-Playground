// Source: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
// Description: Given two integer arrays (values 1–6), return the minimum number of operations
// (change any element to any value 1–6) to make their sums equal, or –1 if impossible.

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        // Quick impossibility check: even maximizing one and minimizing the other
        if (n1 > 6 * n2 || n2 > 6 * n1) return -1;
        
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        // Ensure sum1 <= sum2 by swapping if necessary
        if (sum1 > sum2) {
            swap(sum1, sum2);
            swap(nums1, nums2);
        }
        int diff = sum2 - sum1;
        if (diff == 0) return 0;
        
        // cnt[i] = number of elements that can change the difference by i
        // from nums1 we can increase each x by (6 - x)
        // from nums2 we can decrease each x by (x - 1)
        int cnt[6] = {0};
        for (int x : nums1) cnt[6 - x]++;
        for (int x : nums2) cnt[x - 1]++;
        
        int ops = 0;
        // Greedily use the largest possible changes first
        for (int i = 5; i >= 1 && diff > 0; --i) {
            if (cnt[i] == 0) continue;
            int use = min(cnt[i], (diff + i - 1) / i);
            diff -= use * i;
            ops  += use;
        }
        return ops;
    }
};
