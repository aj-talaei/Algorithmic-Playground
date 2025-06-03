// Problem: Minimum Absolute Sum Difference
// Source  : https://leetcode.com/problems/minimum-absolute-sum-difference/

class Solution {
public:
    int minAbsoluteSumDiff(std::vector<int>& nums1, std::vector<int>& nums2) {
        const int MOD = 1'000'000'007;
        int n = nums1.size();
        long totalDiff = 0;
        int maxReduction = 0;

        // Create a sorted copy of nums1 for binary search
        std::vector<int> sortedNums1(nums1);
        std::sort(sortedNums1.begin(), sortedNums1.end());

        for (int i = 0; i < n; ++i) {
            int a = nums1[i], b = nums2[i];
            int currDiff = std::abs(a - b);
            totalDiff += currDiff;

            // Binary search to find the closest value to b in sortedNums1
            auto it = std::lower_bound(sortedNums1.begin(), sortedNums1.end(), b);
            if (it != sortedNums1.end()) {
                maxReduction = std::max(maxReduction, currDiff - std::abs(*it - b));
            }
            if (it != sortedNums1.begin()) {
                --it;
                maxReduction = std::max(maxReduction, currDiff - std::abs(*it - b));
            }
        }

        return (totalDiff - maxReduction) % MOD;
    }
};
