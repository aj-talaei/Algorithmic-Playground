// Problem: Closest Dessert Cost
// You are given base ice cream costs and optional toppings (each can be used 0, 1, or 2 times).
// You must choose exactly one base and any combination of toppings to get a cost as close as possible to a target.
// Return the closest cost. If there are multiple answers, return the smaller one.

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int best = INT_MAX;

        function<void(int, int)> dfs = [&](int index, int current) {
            if (abs(current - target) < abs(best - target) ||
                (abs(current - target) == abs(best - target) && current < best)) {
                best = current;
            }

            if (index >= toppingCosts.size()) return;

            // Try 0, 1, or 2 of current topping
            dfs(index + 1, current);
            dfs(index + 1, current + toppingCosts[index]);
            dfs(index + 1, current + 2 * toppingCosts[index]);
        };

        for (int base : baseCosts) {
            dfs(0, base);
        }

        return best;
    }
};
