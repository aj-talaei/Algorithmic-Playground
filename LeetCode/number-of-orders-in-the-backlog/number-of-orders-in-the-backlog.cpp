// source: https://leetcode.com/problems/number-of-orders-in-the-backlog/

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        using pii = pair<int, int>; // (price, amount)
        const int MOD = 1e9 + 7;

        // Max-heap for buy orders: highest price first
        priority_queue<pii> buyPQ;

        // Min-heap for sell orders: lowest price first
        priority_queue<pii, vector<pii>, greater<>> sellPQ;

        for (auto& order : orders) {
            int price = order[0], amount = order[1], type = order[2];

            if (type == 0) { // Buy order
                while (amount > 0 && !sellPQ.empty() && sellPQ.top().first <= price) {
                    auto [sellPrice, sellAmt] = sellPQ.top();
                    sellPQ.pop();
                    int matchAmt = min(amount, sellAmt);
                    amount -= matchAmt;
                    sellAmt -= matchAmt;
                    if (sellAmt > 0) sellPQ.emplace(sellPrice, sellAmt);
                }
                if (amount > 0) buyPQ.emplace(price, amount);
            } else { // Sell order
                while (amount > 0 && !buyPQ.empty() && buyPQ.top().first >= price) {
                    auto [buyPrice, buyAmt] = buyPQ.top();
                    buyPQ.pop();
                    int matchAmt = min(amount, buyAmt);
                    amount -= matchAmt;
                    buyAmt -= matchAmt;
                    if (buyAmt > 0) buyPQ.emplace(buyPrice, buyAmt);
                }
                if (amount > 0) sellPQ.emplace(price, amount);
            }
        }

        long long total = 0;
        while (!buyPQ.empty()) {
            total = (total + buyPQ.top().second) % MOD;
            buyPQ.pop();
        }
        while (!sellPQ.empty()) {
            total = (total + sellPQ.top().second) % MOD;
            sellPQ.pop();
        }

        return total;
    }
};
