// Source: https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> remainder(batchSize, 0);
        for (int g : groups) {
            remainder[g % batchSize]++;
        }

        int result = remainder[0]; // Groups that perfectly match the batch size are always happy

        // Pair remainders i and batchSize - i
        for (int i = 1; i <= batchSize / 2; ++i) {
            if (i == batchSize - i) {
                int pairs = remainder[i] / 2;
                result += pairs;
                remainder[i] -= pairs * 2;
            } else {
                int pairs = min(remainder[i], remainder[batchSize - i]);
                result += pairs;
                remainder[i] -= pairs;
                remainder[batchSize - i] -= pairs;
            }
        }

        unordered_map<string, int> memo;
        result += dfs(remainder, 0, batchSize, memo);
        return result;
    }

private:
    int dfs(vector<int>& rem, int currSum, int batchSize, unordered_map<string, int>& memo) {
        string key = encode(rem);
        if (memo.count(key)) return memo[key];

        int maxHappy = 0;
        for (int i = 1; i < batchSize; ++i) {
            if (rem[i] == 0) continue;
            rem[i]--;
            int bonus = (currSum == 0) ? 1 : 0;
            maxHappy = max(maxHappy, bonus + dfs(rem, (currSum + i) % batchSize, batchSize, memo));
            rem[i]++;
        }

        return memo[key] = maxHappy;
    }

    string encode(const vector<int>& rem) {
        string s;
        for (int r : rem) {
            s += to_string(r) + ",";
        }
        return s;
    }
};
