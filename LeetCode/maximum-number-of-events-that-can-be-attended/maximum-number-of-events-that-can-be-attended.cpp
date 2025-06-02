// Source: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by start day
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int day = 0, i = 0, res = 0, n = events.size();

        while (!pq.empty() || i < n) {
            if (pq.empty()) {
                day = events[i][0];
            }

            // Push all events starting on this day
            while (i < n && events[i][0] == day) {
                pq.push(events[i++][1]);
            }

            // Remove expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend one event if available
            if (!pq.empty()) {
                pq.pop();
                res++;
            }

            day++;
        }

        return res;
    }
};
