// Source: https://leetcode.com/problems/maximum-average-pass-ratio/

class Solution {
public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
        auto gain = [](int pass, int total) -> double {
            double before = static_cast<double>(pass) / total;
            double after  = static_cast<double>(pass + 1) / (total + 1);
            return after - before;
        };

        using Class = std::pair<double, std::pair<int, int>>;
        std::priority_queue<Class> pq;

        for (const auto& c : classes) {
            int pass = c[0], total = c[1];
            pq.push({gain(pass, total), {pass, total}});
        }

        while (extraStudents--) {
            auto [_, classInfo] = pq.top(); pq.pop();
            int pass = classInfo.first + 1;
            int total = classInfo.second + 1;
            pq.push({gain(pass, total), {pass, total}});
        }

        double sum = 0.0;
        while (!pq.empty()) {
            auto [_, classInfo] = pq.top(); pq.pop();
            sum += static_cast<double>(classInfo.first) / classInfo.second;
        }

        return sum / classes.size();
    }
};
