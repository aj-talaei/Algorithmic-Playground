// Source : https://leetcode.com/problems/patching-array/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long covered = 0;
        int patches = 0, i = 0;

        while (covered < n) {
            if (i < nums.size() && nums[i] <= covered + 1) {
                covered += nums[i++];
            } else {
                // Patch the smallest number we cannot cover: covered + 1
                covered += covered + 1;
                ++patches;
            }
        }

        return patches;
    }
};
