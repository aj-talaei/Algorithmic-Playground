// Source: https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (int num : nums) sum += num;
        long long diff = abs(goal - sum);
        return (diff + limit - 1) / limit;  // ceiling division
    }
};
