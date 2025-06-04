// Source: https://leetcode.com/problems/minimum-interval-to-include-each-query/

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i) {
            sortedQueries.emplace_back(queries[i], i);
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(queries.size(), -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        int i = 0, n = intervals.size();
        for (const auto& [query, idx] : sortedQueries) {
            // Add intervals that start before or at the query point
            while (i < n && intervals[i][0] <= query) {
                int l = intervals[i][0], r = intervals[i][1];
                minHeap.emplace(r - l + 1, r); // store (length, end)
                ++i;
            }

            // Remove intervals that end before the query point
            while (!minHeap.empty() && minHeap.top().second < query) {
                minHeap.pop();
            }

            if (!minHeap.empty()) {
                result[idx] = minHeap.top().first;
            }
        }

        return result;
    }
};
