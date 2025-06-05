// source: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

class Solution {
public:
    bool canArriveOnTime(const vector<int>& dist, double hour, int speed) {
        double time = 0.0;
        int n = dist.size();

        for (int i = 0; i < n - 1; ++i) {
            time += ceil((double)dist[i] / speed);
        }
        time += (double)dist[n - 1] / speed;

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= n - 1) return -1;

        int low = 1, high = 1e7, answer = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canArriveOnTime(dist, hour, mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};
