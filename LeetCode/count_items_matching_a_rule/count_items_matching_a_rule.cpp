// Problem: Count Items Matching a Rule
// You’re given a list of items where each item = [type, color, name]. Also given a ruleKey (“type”, “color”, or “name”) and a ruleValue.
// Count how many items match: item[field(ruleKey)] == ruleValue.

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx;
        if (ruleKey == "type") {
            idx = 0;
        } else if (ruleKey == "color") {
            idx = 1;
        } else {  // "name"
            idx = 2;
        }
        
        int count = 0;
        for (auto& item : items) {
            if (item[idx] == ruleValue) {
                ++count;
            }
        }
        return count;
    }
};
