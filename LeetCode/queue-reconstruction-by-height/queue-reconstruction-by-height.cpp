// Source : https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort by height descending, then by k ascending
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
        });

        vector<vector<int>> result;
        for (const auto& person : people) {
            result.insert(result.begin() + person[1], person);
        }

        return result;
    }
};
