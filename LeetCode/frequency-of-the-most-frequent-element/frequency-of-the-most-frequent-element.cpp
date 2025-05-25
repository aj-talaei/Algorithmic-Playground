// Source: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// Description: Given an integer array `nums` and an integer `k`, you may increment any element by 1 up to `k` times.
//              Return the maximum frequency of any element after at most `k` total increments.

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long windowSum = 0;
        int left = 0, result = 1;
        
        for (int right = 0; right < nums.size(); ++right) {
            windowSum += nums[right];
            // Ensure we can make all elements in [left..right] equal to nums[right]
            while ((long long)nums[right] * (right - left + 1) - windowSum > k) {
                windowSum -= nums[left++];
            }
            result = max(result, right - left + 1);
        }
        
        return result;
    }
};

