// Source : https://leetcode.com/problems/process-tasks-using-servers/

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using Server = pair<int, int>;     // {weight, index}
        using BusyServer = pair<long long, int>; // {free_time, index}

        auto cmpIdle = [](const Server& a, const Server& b) {
            return a > b; // min-heap by weight, then index
        };

        auto cmpBusy = [](const BusyServer& a, const BusyServer& b) {
            return a > b; // min-heap by free_time
        };

        priority_queue<Server, vector<Server>, decltype(cmpIdle)> idle(cmpIdle);
        priority_queue<BusyServer, vector<BusyServer>, decltype(cmpBusy)> busy(cmpBusy);

        int n = servers.size();
        for (int i = 0; i < n; ++i) {
            idle.push({servers[i], i});
        }

        int m = tasks.size();
        vector<int> result(m);
        long long time = 0;

        for (int i = 0; i < m; ++i) {
            time = max(time, static_cast<long long>(i));

            // Free up servers that have finished their tasks
            while (!busy.empty() && busy.top().first <= time) {
                int idx = busy.top().second;
                idle.push({servers[idx], idx});
                busy.pop();
            }

            // If no idle servers, wait for the next one to be free
            if (idle.empty()) {
                time = busy.top().first;
                while (!busy.empty() && busy.top().first <= time) {
                    int idx = busy.top().second;
                    idle.push({servers[idx], idx});
                    busy.pop();
                }
            }

            // Assign current task
            auto [weight, idx] = idle.top(); idle.pop();
            result[i] = idx;
            busy.push({time + tasks[i], idx});
        }

        return result;
    }
};
