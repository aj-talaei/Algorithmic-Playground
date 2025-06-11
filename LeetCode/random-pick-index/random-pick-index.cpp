// Source : https://leetcode.com/problems/random-pick-index/

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums) : nums(nums) {
        // No need to seed rand() in LeetCode environment; it's handled
    }

    int pick(int target) {
        int count = 0;
        int result = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++count;
                if (rand() % count == 0) {
                    result = i;
                }
            }
        }

        return result;
    }
};
