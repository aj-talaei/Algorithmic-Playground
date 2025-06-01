// Source: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

class Solution {
public:
    int maxDistance(std::vector<int>& nums1, std::vector<int>& nums2) {
        int i = 0, j = 0, maxDist = 0;
        int m = nums1.size(), n = nums2.size();

        while (i < m && j < n) {
            if (nums1[i] > nums2[j]) {
                ++i;
            } else {
                maxDist = std::max(maxDist, j - i);
                ++j;
            }
        }

        return maxDist;
    }
};
