// Problem: Insert Interval
// URL: https://leetcode.com/problems/insert-interval/
// Given a set of non-overlapping intervals sorted by start times, insert a new interval and merge if necessary.

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();
        
        // Add all intervals ending before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i++]);
        }
        
        // Merge all overlapping intervals with newInterval
        vector<int> curr = newInterval;
        while (i < n && intervals[i][0] <= curr[1]) {
            curr[0] = min(curr[0], intervals[i][0]);
            curr[1] = max(curr[1], intervals[i][1]);
            ++i;
        }
        result.push_back(curr);
        
        // Add the remaining intervals
        while (i < n) {
            result.push_back(intervals[i++]);
        }
        
        return result;
    }
};

